#!/usr/bin/env python3
import itertools
import subprocess
import sys

exe = sys.argv[1]
cases = []
want = []
for n in range(1, 9):
    by_inv = {}
    for p in itertools.permutations(range(1, n + 1)):
        inv = sum(p[i] > p[j] for i in range(n) for j in range(i + 1, n))
        by_inv.setdefault(inv, []).append(p)
    for m, ps in by_inv.items():
        for k in {1, len(ps), (len(ps) + 1) // 2, len(ps) + 1}:
            cases.append((n, m, k))
            want.append("-1" if k > len(ps) else " ".join(map(str, ps[k - 1])))

data = str(len(cases)) + "\n" + "\n".join("%d %d %d" % c for c in cases) + "\n"
got = subprocess.run([exe], input=data, text=True, capture_output=True, check=True).stdout.splitlines()
assert got == want, next((i, cases[i], want[i], got[i]) for i in range(len(want)) if i >= len(got) or got[i] != want[i])
print(f"passed {len(cases)} brute-force cases")
