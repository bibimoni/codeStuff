import subprocess, sys, random
random.seed(123)

def run_case(N, T_total=1):
    # build responder: complete binary tree with N nodes (heap-indexed 1..N)
    my = subprocess.Popen(["./c_bin"], stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                          text=True, bufsize=1, cwd="/Users/distiled/codeStuff/cp/cf/pre-icpc-2026/contest/teams/glm-5.3")
    def send(x):
        my.stdin.write(f"{x}\n"); my.stdin.flush()
    send(T_total)
    queries = 0
    cur = 1
    maxq = 0
    responses_remaining = 1  # how many test results to still verify
    while True:
        line = my.stdout.readline()
        if not line:
            my.kill()
            raise SystemExit(f"EOF from solution (N={N}, cur={cur}, queries={queries})")
        line = line.strip()
        if line.startswith("!"):
            ans = int(line[1:])
            maxq = max(maxq, queries)
            assert ans == N, f"WRONG ANSWER for N={N}: got {ans}"
            return maxq
        queries += 1
        assert queries <= 8000, f"too many queries ({queries}) for N={N}"
        cmd = line.split()[1]
        nxt = cur
        if cmd == "L":
            nxt = 2*cur
        elif cmd == "R":
            nxt = 2*cur+1
        elif cmd == "B":
            nxt = cur//2
        if 1 <= nxt <= N:
            send(1)
            cur = nxt
        else:
            send(0)

worst = 0
tests = [1,2,3,6,7,8,15,16,2**30-1, 10**18, 10**17+3, 999999999999999999]
for _ in range(100):
    tests.append(random.randint(1,10**18))
for x in [x for x in tests if x <= 10**18]:
    q = run_case(x)
    worst = max(worst, q)
print("all ok worst queries =", worst)
