#!/usr/bin/env python3
# Local interactor for problem C, to validate the interactive solution offline.
import subprocess, sys, random

def run(N, prog="./C"):
    # heap-indexed complete binary tree with N nodes
    p = subprocess.Popen([prog], stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                         stderr=subprocess.PIPE, text=True, bufsize=1)
    def send(s):
        p.stdin.write(s + "\n"); p.stdin.flush()
    p.stdin.write("1\n"); p.stdin.flush()
    pos = 1
    qc = 0
    while True:
        line = p.stdout.readline()
        if not line:
            return None, qc, "no output"
        line = line.strip()
        if line.startswith("!"):
            return int(line[2:]), qc, "ok"
        assert line.startswith("?"), line
        d = line[2]
        qc += 1
        if qc > 8000:
            return None, qc, "TOO MANY QUERIES"
        nxt = {"L": 2 * pos, "R": 2 * pos + 1, "B": pos // 2}[d]
        if 1 <= nxt <= N:
            pos = nxt
            send("1")
        else:
            send("0")

random.seed(int(sys.argv[1]) if len(sys.argv) > 1 else 1)
worst = 0
tests = [1, 2, 3, 4, 5, 6, 7, 10**18, 10**18 - 1, 2**59, 2**59 + 1, 2**60 - 1 if 2**60-1 <= 10**18 else 10**18]
tests += [random.randint(1, 10**18) for _ in range(12)]
tests += [2**k + d for k in range(1, 60) for d in (0, 1, 2**k // 2, 2**k - 1, 2**k // 3)]
bad = 0
for N in sorted(set(t for t in tests if 1 <= t <= 10**18)):
    got, qc, st = run(N)
    worst = max(worst, qc)
    if got != N:
        print(f"FAIL N={N} got={got} ({st})"); bad += 1
        if bad > 5: break
print("max queries used:", worst)
print("C OK" if bad == 0 else "C FAILED")
