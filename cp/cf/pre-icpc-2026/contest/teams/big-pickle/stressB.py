import subprocess, sys, random, itertools
from collections import deque
random.seed(4242)
def sh(binp, inp):
    return subprocess.run([binp], input=inp, capture_output=True, text=True).stdout

# ================= B: brute force by BFS over 2^n toggle sets =================
def bf_B(n, edges, s):
    # state: tuple of bits; BFS over reachable states, collect one that is all-1
    start = tuple(int(c) for c in s)
    seen = {start: None}
    dq = deque([start])
    while dq:
        st = dq.popleft()
        if all(st): return st
        for u in range(n):
            ns = list(st); ns[u] ^= 1
            for v, w in edges:
                if v == u: ns[w] ^= 1
                if w == u: ns[v] ^= 1
            ns = tuple(ns)
            if ns not in seen: seen[ns] = st; dq.append(ns)
    return None

bad = 0
cases = []
for _ in range(120):
    n = random.randint(1, 8)
    E = set()
    for _ in range(random.randint(0, n*2)):
        u, v = random.randrange(n), random.randrange(n)
        if u != v: E.add((min(u,v), max(u,v)))
    edges = [(u, v) for u, v in E]
    q = random.randint(1, 5)
    qs = [''.join(random.choice('01') for _ in range(n)) for _ in range(q)]
    cases.append((n, edges, qs))
i = 0
for n, edges, qs in cases:
    inp = f"{n} {len(edges)} {len(qs)}\n"
    for u, v in edges: inp += f"{u+1} {v+1}\n"
    for s in qs: inp += " ".join(s) + "\n"
    lines = sh("./B", inp).strip().split("\n")
    assert len(lines) == len(qs), (n, edges, qs, lines)
    for s, o in zip(qs, lines):
        want = bf_B(n, edges, s)
        if want is None:
            if o.strip() != "-1":
                print("B MISMATCH(exp -1)", n, edges, s, o); bad += 1
        else:
            if o.strip() == "-1":
                print("B MISMATCH(got -1)", n, edges, s, want); bad += 1
            else:
                toks = o.split()
                k = int(toks[0]); ops = [int(x)-1 for x in toks[1:]]
                if len(ops) != k or len(set(ops)) != k: print("B badout", o); bad += 1; continue
                st = [int(c) for c in s]
                for u in ops:
                    st[u] ^= 1
                    for v, w in edges:
                        if v == u: st[w] ^= 1
                        if w == u: st[v] ^= 1
                if st != list(want):
                    print("B MISMATCH", n, edges, s, o, st, want); bad += 1
        if bad > 5: sys.exit(1)
print("B ok" if bad == 0 else "B FAILED")
