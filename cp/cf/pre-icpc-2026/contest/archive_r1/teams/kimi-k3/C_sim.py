import subprocess, sys

def run_test(prog, N, budget=8000):
    p = subprocess.Popen([prog], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True, bufsize=1)
    p.stdin.write("1\n"); p.stdin.flush()
    pos = 1
    queries = 0
    while True:
        line = p.stdout.readline()
        if not line:
            return None, queries, "EOF"
        line = line.strip()
        if not line:
            continue
        if line.startswith("!"):
            ans = int(line.split()[1])
            p.stdin.close()
            p.wait(timeout=5)
            return ans, queries, ("OK" if ans == N else "WRONG")
        # "? X"
        _, mv = line.split()
        queries += 1
        if queries > budget:
            p.kill()
            return None, queries, "BUDGET"
        nxt = pos
        if mv == 'L':
            nxt = pos * 2
        elif mv == 'R':
            nxt = pos * 2 + 1
        else:
            nxt = pos // 2 if pos > 1 else 0
        if 1 <= nxt <= N:
            pos = nxt
            p.stdin.write("1\n")
        else:
            p.stdin.write("0\n")
        p.stdin.flush()

prog = sys.argv[1]
tests = [1, 2, 3, 4, 5, 6, 7, 8, 15, 16, 17, 2**59 - 1, 2**59, 2**59 + 1, 2**60 - 1, 10**18, 10**18 - 1, 999983, 5]
worst = 0
for N in tests:
    ans, q, st = run_test(prog, N)
    worst = max(worst, q)
    print(f"N={N}: ans={ans} queries={q} status={st}")
    if st != "OK":
        sys.exit(1)
import random
for s in range(30):
    random.seed(s)
    N = random.randint(1, 10**18)
    ans, q, st = run_test(prog, N)
    worst = max(worst, q)
    if st != "OK":
        print(f"N={N}: ans={ans} queries={q} status={st}")
        sys.exit(1)
print(f"all OK, worst queries = {worst}")
