#!/usr/bin/env python3
# Stress M vs M_brute: exhaustive (n<=6: every m, edge k's + sampled k)
# and random rounds (n<=8).
import random, subprocess, sys, os

D = os.path.dirname(os.path.abspath(__file__)) + "/.."

def run(inp):
    a = subprocess.run([f"{D}/M"], input=inp, capture_output=True, text=True).stdout
    b = subprocess.run([f"{D}/tests/M_brute"], input=inp, capture_output=True, text=True).stdout
    return a, b

def check(cases, label):
    inp = str(len(cases)) + "\n" + "".join(f"{n} {m} {k}\n" for n, m, k in cases)
    a, b = run(inp)
    if a != b:
        print(f"MISMATCH [{label}]")
        print("input:\n" + inp)
        al, bl = a.splitlines(), b.splitlines()
        for i, (x, y) in enumerate(zip(al, bl)):
            if x != y:
                print(f"case {i}: M={x!r} brute={y!r}")
        sys.exit(1)

# exhaustive small n: every m; k in edges + full sweep for tiny counts
rng = random.Random(12345)
for n in range(1, 7):
    mm = n * (n - 1) // 2
    cases = []
    for m in range(mm + 1):
        ks = {1, 2, 3, 4, 5}
        # count of perms (small n) -> brute all k in 1..cnt+2
        import math
        # Mahonian count via DP
        def count(n, m):
            dp = [1]
            for i in range(1, n + 1):
                ndp = [0] * (i * (i - 1) // 2 + 1)
                w = 0
                for j in range(len(ndp)):
                    if j < len(dp): w += dp[j]
                    if j - i >= 0: w -= dp[j - i]
                    ndp[j] = w
                dp = ndp
            return dp[m] if m < len(dp) else 0
        c = count(n, m)
        if c <= 60:
            ks.update(range(6, c + 3))
        else:
            ks.update([c, c + 1, c + 2, c // 2, 10**18])
        for k in sorted(ks):
            cases.append((n, m, k))
    # chunk to keep sum n <= 300 per file (statement guarantee)
    for i in range(0, len(cases), 40):
        chunk = cases[i:i + 40]
        while sum(c[0] for c in chunk) > 300:
            chunk = chunk[:len(chunk) // 2]
        check(chunk, f"exhaustive n={n} [{i}]")
    print(f"exhaustive n={n}: OK ({len(cases)} cases)")

# random rounds, n <= 8
for r in range(60):
    cases = []
    tot = 0
    while True:
        n = rng.randint(1, 8)
        if tot + n > 300 or len(cases) >= 60: break
        tot += n
        mm = n * (n - 1) // 2
        m = rng.randint(0, mm)
        pick = rng.random()
        if pick < 0.3: k = rng.randint(1, 20)
        elif pick < 0.7: k = rng.randint(1, 10**18)
        else: k = rng.randint(max(1, mm), 10**9)
        cases.append((n, m, k))
    check(cases, f"random round {r}")
print("ALL STRESS PASS")
