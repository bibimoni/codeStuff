#!/usr/bin/env python3
"""Bonus round: every team gets <=20 min wall on problem M (dp-counting-med).
usage: sprint.py <team> <model-id> [--session id]"""
import json, os, subprocess, sys, time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CONTEST = os.path.join(ROOT, "contest")
team, model = sys.argv[1], sys.argv[2]
sid = None
if "--session" in sys.argv:
    sid = sys.argv[sys.argv.index("--session") + 1]

TEAM = os.path.join(CONTEST, "teams", team)
prompt = (f"BONUS ROUND, team {team}. One new problem: M — sheet at "
          "/Users/distiled/codeStuff/cp/cf/pre-icpc-2026/contest/problems/M.txt "
          "(K-th Inversion Permutation: n,m,k -> k-th lexicographic permutation with exactly m inversions, -1 if fewer than k). "
          f"You have 20 MINUTES of wall clock. Do NOT re-read old sheets; M is the only target. "
          "Write C++17 in your workspace, submit via: "
          "cd /Users/distiled/codeStuff/cp/cf/pre-icpc-2026 && python3 contest/judge.py submit M "
          f"contest/teams/{team}/<file>.cpp --team {team} . "
          "Spam-submitting is allowed. Iterate on verdicts. Speed is the whole game here. "
          "LOOP CONTRACT: every reply must end with a tool call. When the judge says OK, reply DONE.")
cmd = ["opencode", "run", "--format", "json"]
if sid: cmd += ["--session", sid]
cmd += ["-m", model, prompt]

ev = open(os.path.join(TEAM, "_events.log"), "a")
proc = subprocess.Popen(cmd, cwd=TEAM, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True)
deadline = time.time() + 20 * 60
def parse(line):
    try: e = json.loads(line)
    except Exception: return None
    t = e.get("type"); part = e.get("part") or {}
    if t == "text":
        tx = " ".join(str(part.get("text", "")).split())
        return ("chat: " + tx[:220]) if tx else None
    if t in ("tool_use", "tool_call"):
        tool = part.get("tool") or "?"; inp = ((part.get("state") or {}).get("input") or part.get("input") or {})
        if isinstance(inp, dict) and tool == "bash": return "$ " + str(inp.get("command",""))[:220]
        if isinstance(inp, dict):
            for f in ("filePath","file","path"):
                if inp.get(f): return f"-> {tool} {os.path.basename(str(inp[f]))}"
        return f"-> {tool}"
    return None
try:
    t0 = time.time()
    while time.time() < deadline:
        line = proc.stdout.readline()
        if not line: break
        c = parse(line)
        if c: ev.write(time.strftime("%H:%M:%S ") + c + "\n"); ev.flush()
    if proc.poll() is None:
        proc.terminate()
        time.sleep(3)
        if proc.poll() is None: proc.kill()
        ev.write(time.strftime("%H:%M:%S ") + "[SPRINT TIME-OUT: killed at 20 min]\n")
except Exception as ex:
    ev.write(f"sprint error: {ex}\n")
ev.close()
print(f"[{team}] sprint done", flush=True)
