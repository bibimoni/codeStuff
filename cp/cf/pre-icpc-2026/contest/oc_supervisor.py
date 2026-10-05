#!/usr/bin/env python3
"""Supervise one opencode-headless contestant until feedback.md exists or the
contest window ends.

v6: sessions are PINNED by session id (opencode's -c roulette grabs the most
recent session PROJECT-WIDE — that cross-contaminated contestants who shared a
git root). First run captures sessionID from the JSON event stream into
.oc_session_id; every later attempt reuses exactly that session.

usage: oc_supervisor.py <team> <model-id>
"""
import json, os, subprocess, sys, time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CONTEST = os.path.join(ROOT, "contest")
TEAM = os.path.join(CONTEST, "teams", sys.argv[1])
MODEL = sys.argv[2]
VARIANT = sys.argv[3] if len(sys.argv) > 3 else None
TMPL = open(os.path.join(CONTEST, "contestant_prompt.txt")).read()

def parse_event(line):
    """opencode --format json eventline -> (sid, compact readable str|None)."""
    try:
        e = json.loads(line)
    except Exception:
        return None, None
    sid = e.get("sessionID")
    t = e.get("type")
    part = e.get("part") or {}
    if t == "text":
        txt = " ".join(str(part.get("text", "")).split())
        return sid, (("chat: " + txt[:220]) if txt else None)
    if t in ("tool_use", "tool_call"):
        tool = part.get("tool") or part.get("name") or "?"
        inp = ((part.get("state") or {}).get("input") or part.get("input") or {})
        if isinstance(inp, dict):
            if tool == "bash":
                return sid, "$ " + str(inp.get("command", ""))[:220]
            for f in ("filePath", "file", "path"):
                if inp.get(f):
                    return sid, f"-> {tool} {os.path.basename(str(inp[f]))}"
        return sid, f"-> {tool}"
    return sid, None

def run_with_events(cmd):
    proc = subprocess.Popen(cmd, cwd=TEAM, stdout=subprocess.PIPE,
                            stderr=subprocess.DEVNULL, text=True, bufsize=1)
    sid = None
    with open(os.path.join(TEAM, "_events.log"), "a") as ev:
        while True:
            line = proc.stdout.readline()
            if not line:
                break
            s, c = parse_event(line)
            if s and not sid:
                sid = s
            if c:
                ev.write(time.strftime("%H:%M:%S ") + c + "\n")
                ev.flush()
    return proc.wait(), sid

os.makedirs(TEAM, exist_ok=True)
SID_FILE = os.path.join(TEAM, ".oc_session_id")
attempt = 0
while True:
    meta = json.load(open(os.path.join(CONTEST, "meta.json")))
    remaining = meta["duration_s"] - (time.time() - meta["start_ts"])
    if os.path.exists(os.path.join(TEAM, "feedback.md")):
        print(f"[{sys.argv[1]}] feedback.md present -> done", flush=True)
        break
    if remaining <= 0:
        print(f"[{sys.argv[1]}] window over", flush=True)
        break
    attempt += 1
    sid = open(SID_FILE).read().strip() if os.path.exists(SID_FILE) else None
    print(f"[{sys.argv[1]}] opencode attempt {attempt} (session {'PINNED' if sid else 'fresh'}), {remaining/60:.0f} min left", flush=True)
    if sid:
        prompt = ("URGENT PACING: do NOT read many sheets before producing. Pick the easiest-looking problem NOW, "
                  "write it, submit within the next few minutes, then iterate problem-by-problem. "
                  "A real contestant banks fast points early. "

                  "(failed tries on unsolved problems cost nothing); stress-test locally with a "
                  "brute-force harness when feasible; and when stuck >20min you may run "
                  "`curl -s localhost:8777/api/state | python3 -m json.tool` (only network call allowed). ")
        prompt += (f"Contest clock: {remaining/60:.0f} min left. Continue EXACTLY where you left off. "
                  "Do NOT re-read sheets you already read; check STRATEGY.md briefly. "
                  "If you have a solution drafted for any problem, submit it via the judge NOW; "
                  "iterate on judge output. LOOP CONTRACT: every reply must end with a tool call. "
                  "Write feedback.md before the window closes.")
        cmd = ["opencode", "run", "--format", "json", "--session", sid, "-m", MODEL] + (["--variant", VARIANT] if VARIANT else []) + [prompt]
    else:
        prompt = TMPL.replace("{NAME}", sys.argv[1]).replace(
            "{REMAINING}", "You have %.1f hours of contest window left; plan accordingly."
            % (remaining / 3600.0)).replace("{RESUME}", "This is your first start.")
        cmd = ["opencode", "run", "--format", "json", "-m", MODEL] + (["--variant", VARIANT] if VARIANT else []) + [prompt]
    try:
        rc, new_sid = run_with_events(cmd)
        if new_sid and not sid:
            open(SID_FILE, "w").write(new_sid)
            print(f"[{sys.argv[1]}] pinned session {new_sid}", flush=True)
        print(f"[{sys.argv[1]}] opencode exited rc={rc}", flush=True)
    except subprocess.TimeoutExpired:
        print(f"[{sys.argv[1]}] opencode hit 60min supervisor cap, relaunching", flush=True)
    except Exception as e:
        print(f"[{sys.argv[1]}] opencode spawn error: {e}", flush=True)
    time.sleep(10)
