#!/usr/bin/env python3
"""Local contest judge (macOS-native runner).

Usage:
  python3 contest/judge.py submit <LETTER> <source.cpp> --team <name>
  python3 contest/judge.py limits                     # show per-problem TL/ML

Compiles with g++ -O2 -std=gnu++17, runs every test, verifies with the
problem's own testlib checker (compiled once per problem, cached).
Interactive problems (inter flag in map.txt): interactor <-> solution over
two FIFOs, interactor exit code is the verdict.

Limits: CPU time via RLIMIT_CPU = TL (fair under parallel load), wall-time
backstop = 4*TL+5s kill, memory via RSS polling -> ML if peak > 1.05*ML.

Every submission appends one JSON line to contest/results/<team>.jsonl:
{"ts","letter","verdict","first_fail","passed","total","time_ms","file"}
verdict in OK | WA | TL | ML | RE | CE | JE (judge error).
"""
import json, os, resource, signal, subprocess, sys, tempfile, time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CONTEST = os.path.join(ROOT, "contest")
J = os.path.join(CONTEST, "_judge")
RESULTS = os.path.join(CONTEST, "results")

def load_map():
    out = {}
    for line in open(os.path.join(CONTEST, "map.txt")):
        p = line.split()
        out[p[0]] = dict(pid=p[1], slug=p[2],
                         tl=int(p[3].split("=")[1]) / 1000.0,
                         ml=int(p[4].split("=")[1]),
                         inter=p[5].split("=")[1] == "1",
                         tdir=p[7].split("=", 1)[1])
    return out

def tname(i):
    return f"{i:02d}"

def compile_cpp(src, bin_path, timeout=60):
    r = subprocess.run(["g++-14", "-O2", "-std=gnu++17", "-o", bin_path, src],
                       capture_output=True, text=True, timeout=timeout)
    return r.returncode == 0, (r.stderr or "")[-1200:]

def get_checker(letter):
    """Compile (once) and return the checker binary path."""
    cache = os.path.join(J, letter, ".check_bin")
    src = None
    for cand in ("check.cpp", "checker.cpp"):
        p = os.path.join(J, letter, "files", cand)
        if os.path.exists(p):
            src = p
            break
    if src is None:
        raise RuntimeError(f"no checker source under {letter}/files")
    if os.path.exists(cache) and os.path.getmtime(cache) > os.path.getmtime(src):
        return cache
    ok, err = compile_cpp(src, cache)
    if not ok:
        raise RuntimeError(f"checker compile failed for {letter}: {err[:400]}")
    return cache

def get_interactor(letter):
    cache = os.path.join(J, letter, ".inter_bin")
    src = os.path.join(J, letter, "files", "interactor.cpp")
    if os.path.exists(cache) and os.path.getmtime(cache) > os.path.getmtime(src):
        return cache
    ok, err = compile_cpp(src, cache)
    if not ok:
        raise RuntimeError(f"interactor compile failed for {letter}: {err[:400]}")
    return cache

def run_limited(argv, stdin_path, stdout_path, tl, ml_mb):
    """fork+wait4 runner: per-child rusage (exact CPU time + peak RSS, immune
    to pollution by the judge's other children). Mid-run RSS kill via ps.
    Returns (verdict, peak_rss_mb, elapsed_ms)."""
    tl_cpu = int(tl) + 2  # RLIMIT backstop; verdict uses ru_utime+ru_stime
    wall_deadline = 4 * tl + 5.0
    bin_abs = os.path.abspath(argv[0])
    pid = os.fork()
    if pid == 0:  # child: no python I/O from here
        try:
            resource.setrlimit(resource.RLIMIT_CPU, (tl_cpu, tl_cpu + 1))
            resource.setrlimit(resource.RLIMIT_NOFILE, (256, 256))
            fi = os.open(stdin_path, os.O_RDONLY)
            os.dup2(fi, 0)
            fo = os.open(stdout_path, os.O_WRONLY | os.O_CREAT | os.O_TRUNC, 0o666)
            os.dup2(fo, 1)
            devnull = os.open(os.devnull, os.O_WRONLY)
            os.dup2(devnull, 2)
            os.execv(bin_abs, [bin_abs])
        finally:
            os._exit(127)
    t0 = time.monotonic()
    poll_peak = 0.0
    status = ru = None
    next_ps = t0 + 0.08
    while True:
        wpid, status, ru = os.wait4(pid, os.WNOHANG)
        if wpid:
            break
        now = time.monotonic()
        if now >= next_ps:
            next_ps = now + 0.025
            try:
                pr = subprocess.run(["ps", "-o", "rss=", "-p", str(pid)],
                                    capture_output=True, text=True, timeout=2)
                if pr.stdout.strip():
                    poll_peak = max(poll_peak, int(pr.stdout.strip()) / 1024.0)
            except Exception:
                pass
            if poll_peak > ml_mb:
                os.kill(pid, 9)
                os.wait4(pid, 0)
                return "ML", poll_peak, (now - t0) * 1000
        if now - t0 > wall_deadline:
            os.kill(pid, 9)
            os.wait4(pid, 0)
            return "TL", poll_peak, (now - t0) * 1000
        time.sleep(0.005)
    el = (time.monotonic() - t0) * 1000
    cpu = ru.ru_utime + ru.ru_stime
    peak = max(poll_peak, ru.ru_maxrss / 1048576.0)
    if peak > ml_mb:
        return "ML", peak, el
    if os.WIFSIGNALED(status) and os.WTERMSIG(status) == signal.SIGXCPU:
        return "TL", peak, el
    if cpu > tl * 1.02:
        return "TL", peak, el
    if os.WIFSIGNALED(status) or os.WEXITSTATUS(status) != 0:
        return "RE", peak, el
    return "RUN_OK", peak, el

def check_output(letter, tdir, test, outp, inter):
    """Run testlib checker. verdict OK/WA/JE."""
    if inter:
        return "OK", ""  # interactor already decided
    chk = get_checker(letter)
    r = subprocess.run([chk, os.path.join(tdir, test),
                        outp,
                        os.path.join(tdir, test + ".a")],
                       capture_output=True, text=True, timeout=60)
    if r.returncode == 0:
        return "OK", ""
    if r.returncode == 1:
        return "WA", (r.stderr or "")[:150]
    if r.returncode == 2:
        return "WA", (r.stderr or "")[:150]  # presentation error counts as WA here
    return "JE", f"checker rc={r.returncode} {(r.stderr or '')[:150]}"

def run_interactive_final(letter, sol_bin, tdir, test, tl, ml_mb):
    """testlib convention: interactor stdin/stdout <-> solution stdout/stdin;
    argv[1]=test input, argv[2]=transcript file (written by interactor).
    Verdict = interactor exit code (0 OK, 1 WA, 2 PE->WA, else judge error/RE)."""
    inter = get_interactor(letter)
    tin = os.path.join(tdir, test)
    tl_cpu = int(tl) + 2
    with tempfile.TemporaryDirectory(prefix="inter") as work:
        transcript = os.path.join(work, "transcript.txt")
        to_sol_r, to_sol_w = os.pipe()       # interactor.stdout -> sol.stdin
        to_int_r, to_int_w = os.pipe()       # sol.stdout -> interactor.stdin

        def pre():
            resource.setrlimit(resource.RLIMIT_CPU, (tl_cpu, tl_cpu + 1))

        t0 = time.monotonic()
        inter_p = subprocess.Popen([inter, tin, transcript],
                                   stdin=to_int_r, stdout=to_sol_w,
                                   stderr=subprocess.PIPE)
        os.close(to_int_r); os.close(to_sol_w)
        sol_p = subprocess.Popen([sol_bin], stdin=to_sol_r, stdout=to_int_w,
                                 stderr=subprocess.DEVNULL, preexec_fn=pre)
        os.close(to_sol_r); os.close(to_int_w)
        peak = 0.0
        wall_deadline = 4 * tl + 6.0
        while inter_p.poll() is None and sol_p.poll() is None:
            try:
                pr = subprocess.run(["ps", "-o", "rss=", "-p", str(sol_p.pid)],
                                    capture_output=True, text=True, timeout=2)
                if pr.stdout.strip():
                    peak = max(peak, int(pr.stdout.strip()) / 1024.0)
            except Exception:
                pass
            if peak > ml_mb * 1.05:
                sol_p.kill(); inter_p.kill()
                return "ML", "", (time.monotonic() - t0) * 1000
            if time.monotonic() - t0 > wall_deadline:
                sol_p.kill(); inter_p.kill()
                return "TL", "", (time.monotonic() - t0) * 1000
            time.sleep(0.01)
        try:
            _, ie = inter_p.communicate(timeout=30)
        except Exception:
            inter_p.kill(); _, ie = inter_p.communicate()
        el = (time.monotonic() - t0) * 1000
        irc = inter_p.returncode if inter_p.returncode is not None else 3
        ie = (ie or b"").decode(errors="replace").strip()
        if irc == 0:
            return "OK", "", el
        if irc in (1, 2):
            return "WA", ie[:150], el
        if sol_p.poll() not in (None, 0):
            return "RE", f"sol rc={sol_p.returncode}; {ie[:100]}", el
        return "JE", f"interactor rc={irc} {ie[:150]}", el

def judge(letter, src, team):
    m = load_map()[letter]
    eff_ml = m["ml"] * 1.05
    try:
        eff_ml = max(eff_ml, json.load(open(os.path.join(CONTEST, "calib.json"))).get(letter, 0))
    except Exception:
        pass
    tdir = m["tdir"]
    tests = sorted((f for f in os.listdir(tdir)
                    if not f.endswith(".a") and not f.endswith(".out")),
                   key=lambda s: int(s))
    with tempfile.TemporaryDirectory(prefix="judge") as td:
        bin_path = os.path.join(td, "sol")
        ok, err = compile_cpp(src, bin_path)
        if not ok:
            return dict(verdict="CE", first_fail=None, passed=0,
                        total=len(tests), time_ms=0, note=err)
        max_ms, passed, peak_any = 0, 0, 0.0
        for test in tests:
            outp = os.path.join(td, f"{test}.out")
            if m["inter"]:
                v, note, el = run_interactive_final(letter, bin_path, tdir, test,
                                                    m["tl"], m["ml"])
                if v == "OK":
                    passed += 1; max_ms = max(max_ms, el); continue
                return dict(verdict=v, first_fail=int(test), passed=passed,
                            total=len(tests), time_ms=int(max_ms), note=note)
            v, peak, el = run_limited([bin_path], os.path.join(tdir, test),
                                      outp, m["tl"], eff_ml)
            peak_any = max(peak_any, peak)
            if v == "RUN_OK":
                try:
                    cv, note = check_output(letter, tdir, test, outp, m["inter"])
                except Exception as e:
                    cv, note = "JE", str(e)[:150]
                if cv == "OK":
                    passed += 1; max_ms = max(max_ms, el); continue
                if cv == "JE":
                    return dict(verdict="JE", first_fail=int(test), passed=passed,
                                total=len(tests), time_ms=int(max_ms), note=note)
                return dict(verdict="WA", first_fail=int(test), passed=passed,
                            total=len(tests), time_ms=int(max_ms),
                            note=note)
            return dict(verdict=v, first_fail=int(test), passed=passed,
                        total=len(tests), time_ms=int(max_ms), note="peak %.1fMB" % peak_any)
        return dict(verdict="OK", first_fail=None, passed=passed,
                    total=len(tests), time_ms=int(max_ms),
                    note="peak %.1fMB" % peak_any)

def main():
    if len(sys.argv) >= 2 and sys.argv[1] == "limits":
        for L, m in sorted(load_map().items()):
            print(f"{L}: {m['slug']:22s} TL={m['tl']:5.2f}s ML={m['ml']:4d}MB" +
                  (" INTERACTIVE" if m["inter"] else ""))
        return
    if len(sys.argv) < 4 or sys.argv[1] != "submit":
        sys.exit(__doc__)
    letter, src = sys.argv[2].upper(), os.path.abspath(sys.argv[3])
    team = "anon"
    if "--team" in sys.argv:
        team = sys.argv[sys.argv.index("--team") + 1]
    t0 = time.time()
    res = judge(letter, src, team)
    rec = dict(ts=t0, letter=letter, verdict=res["verdict"],
               first_fail=res["first_fail"], passed=res["passed"],
               total=res["total"], time_ms=res["time_ms"],
               file=os.path.basename(src))
    os.makedirs(RESULTS, exist_ok=True)
    with open(os.path.join(RESULTS, f"{team}.jsonl"), "a") as f:
        f.write(json.dumps(rec) + "\n")
    extra = f" | {res['note']}" if res.get("note") else ""
    ff = f" on test {res['first_fail']}" if res["first_fail"] else ""
    print(f"{res['verdict']}{ff} ({res['passed']}/{res['total']}, max {res['time_ms']}ms){extra}")

if __name__ == "__main__":
    main()
