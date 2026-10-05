import subprocess, random, sys

def solve_brute(n, edges, b):
    A = [[0]*n for _ in range(n)]
    for i in range(n): A[i][i] = 1
    for u, v in edges:
        A[u][v] ^= 1; A[v][u] ^= 1
    row = [r[:] for r in A]
    rhs = b[:]
    r = 0
    pivcols = []
    for c in range(n):
        p = None
        for i in range(r, n):
            if row[i][c]: p = i; break
        if p is None: continue
        row[r], row[p] = row[p], row[r]
        rhs[r], rhs[p] = rhs[p], rhs[r]
        for i in range(n):
            if i != r and row[i][c]:
                for j in range(n): row[i][j] ^= row[r][j]
                rhs[i] ^= rhs[r]
        pivcols.append(c)
        r += 1
    for i in range(r, n):
        if rhs[i]: return None
    x = [0]*n
    for i, c in enumerate(pivcols):
        x[c] = rhs[i]
    return x

def check_line(n, edges, init, line, bad_holder):
    b = [1 - int(ch) for ch in init]
    exp = solve_brute(n, edges, b)
    if line == '-1':
        if exp is not None:
            bad_holder[0] += 1; print('MISMATCH solvable but -1', n, edges, init)
            return
        return
    toks = list(map(int, line.split()))
    if not toks:
        bad_holder[0] += 1; print('EMPTY LINE', init); return
    K = toks[0]; xs = toks[1:]
    if K != len(xs) or len(set(xs)) != K or any(x < 1 or x > n for x in xs):
        bad_holder[0] += 1; print('BAD FORMAT', line); return
    x = [0]*n
    for v in xs: x[v-1] = 1
    for i in range(n):
        s = x[i]
        for u, v in edges:
            if u == i and x[v]: s ^= 1
            if v == i and x[u]: s ^= 1
        if (s & 1) != b[i]:
            bad_holder[0] += 1; print('WRONG ANSWER', n, edges, init, line); return
    if exp is None:
        bad_holder[0] += 1; print('MISMATCH unsat but answered', init, line)

random.seed(11)
bad = [0]
total = 0
for trial in range(40):
    n = random.randint(1, 40)
    m = random.randint(0, min(n*(n-1)//2, 60))
    edges = set()
    while len(edges) < m:
        u, v = random.randint(0, n-1), random.randint(0, n-1)
        if u != v: edges.add((min(u,v), max(u,v)))
    edges = sorted(edges)
    q = random.randint(1, 8)
    inits = [''.join(random.choice('01') for _ in range(n)) for _ in range(q)]
    inp = [f"{n} {len(edges)} {q}"]
    for u, v in edges:
        inp.append(f"{u+1} {v+1}")
    inp += inits
    inp = '\n'.join(inp) + '\n'
    out = subprocess.run(['./Btest'], input=inp, capture_output=True, text=True)
    lines = out.stdout.split('\n')
    got = [l for l in lines[:q]]
    if len([l for l in lines if l.strip()]) != q:
        bad[0] += 1; print('LINE COUNT', trial, repr(out.stdout)); continue
    for init, line in zip(inits, got):
        check_line(n, edges, init, line, bad)
        total += 1
print('B checked', total, 'queries, bad', bad[0])
sys.exit(1 if bad[0] else 0)
