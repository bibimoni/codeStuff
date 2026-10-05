#!/usr/bin/env python3
# Stress: random small grids, brute recompute beta=E-V+C after each hit prefix.
import random, subprocess, sys

DR = [-1, 0, 1, 0]; DC = [0, 1, 0, -1]
BIT = [1, 2, 4, 8]; OPP = [4, 8, 1, 2]
VALID = [m for m in range(16) if m == 0 or bin(m).count("1") >= 2]

def brute(n, m, g, hits):
    N = n * m
    out = []
    alive = [g[i] != 0 for i in range(N)]
    for i in range(len(hits) + 1):
        if i > 0:
            alive[hits[i - 1]] = False
        # recompute from scratch
        par = list(range(N))
        def find(x):
            while par[x] != x:
                par[x] = par[par[x]]
                x = par[x]
            return x
        V = E = C = 0
        for x in range(N):
            if alive[x]:
                V += 1; C += 1
        for x in range(N):
            if not alive[x]:
                continue
            r, c = divmod(x, m)
            for d in range(4):
                if not (g[x] & BIT[d]):
                    continue
                nr, nc = r + DR[d], c + DC[d]
                if not (0 <= nr < n and 0 <= nc < m):
                    continue
                y = nr * m + nc
                if alive[y] and (g[y] & OPP[d]):
                    E += 1
                    ra, rb = find(x), find(y)
                    if ra != rb:
                        par[ra] = rb
                        C -= 1
        E //= 2  # each edge counted from both endpoints
        out.append(E - V + C)
    return out[1:]  # after 1..q impacts

def gen(seed):
    rng = random.Random(seed)
    n = rng.randint(1, 5)
    m = rng.randint(1, 5)
    g = [rng.choice(VALID) for _ in range(n * m)]
    # bias: sometimes all 15 (loop-heavy), sometimes sparse
    mode = rng.randint(0, 3)
    if mode == 0:
        g = [15 if rng.random() < 0.7 else 0 for _ in range(n * m)]
    elif mode == 1:
        g = [rng.choice([0, 3, 5, 6, 9, 10, 12]) for _ in range(n * m)]
    jx = [i for i in range(n * m) if g[i] != 0]
    rng.shuffle(jx)
    q = rng.randint(0, len(jx))
    hits = jx[:q]
    return n, m, g, hits

def to_input(cases):
    lines = [str(len(cases))]
    for n, m, g, hits in cases:
        lines.append(f"{n} {m}")
        for r in range(n):
            lines.append(" ".join(str(g[r * m + c]) for c in range(m)))
        lines.append(str(len(hits)))
        for h in hits:
            r, c = divmod(h, m)
            lines.append(f"{r + 1} {c + 1}")
    return "\n".join(lines) + "\n"

def expected(cases):
    out = []
    for n, m, g, hits in cases:
        out.append(" ".join(map(str, brute(n, m, g, hits))))
    return "\n".join(out) + "\n"

def main():
    iters = int(sys.argv[1]) if len(sys.argv) > 1 else 500
    for seed in range(iters):
        cases = [gen(seed * 100 + k) for k in range(random.Random(seed).randint(1, 4))]
        inp = to_input(cases)
        exp = expected(cases)
        got = subprocess.run(["./I"], input=inp, capture_output=True, text=True).stdout
        if got != exp:
            print(f"MISMATCH seed={seed}")
            print("INPUT:\n" + inp)
            print("EXPECTED:\n" + repr(exp))
            print("GOT:\n" + repr(got))
            sys.exit(1)
    print(f"OK {iters} seeds")

main()
