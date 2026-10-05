import subprocess, random, sys

def brute(n, m, g, impacts):
    present = [True]*(n*m)
    res = []
    for (r, c) in impacts:
        present[(r-1)*m+(c-1)] = False
        E = 0
        par = list(range(n*m))
        def find(x):
            while par[x] != x:
                par[x] = par[par[x]]; x = par[x]
            return x
        comps = 0
        for i in range(n*m):
            if present[i]: comps += 1
        for r2 in range(n):
            for c2 in range(m):
                i = r2*m+c2
                if not present[i]: continue
                for d, (dr, dc) in enumerate([(-1,0),(0,1),(1,0),(0,-1)]):
                    nr, nc = r2+dr, c2+dc
                    if not (0 <= nr < n and 0 <= nc < m): continue
                    j = nr*m+nc
                    if j <= i or not present[j]: continue
                    if (g[i] >> d) & 1 and (g[j] >> ((d+2) % 4)) & 1:
                        E += 1
                        a, b = find(i), find(j)
                        if a != b:
                            par[a] = b; comps -= 1
        res.append(E - sum(1 for x in present if x) + comps)
    return res

random.seed(7)
tests = []
expected = []
for _ in range(60):
    n = random.randint(1, 5); m = random.randint(1, 5)
    g = [random.randint(0, 15) for _ in range(n*m)]
    # force junctions to have >=2 openings where nonzero? statement guarantees; keep as-is (0 allowed as empty)
    jc = [i for i in range(n*m) if g[i] != 0]
    random.shuffle(jc)
    q = random.randint(0, len(jc))
    impacts = [(i//m+1, i%m+1) for i in jc[:q]]
    tests.append((n, m, g, impacts))
    expected.append(brute(n, m, g, impacts))

inp = [str(len(tests))]
for n, m, g, imp in tests:
    inp.append(f"{n} {m}")
    inp.append(' '.join(map(str, g)))
    inp.append(str(len(imp)))
    for r, c in imp:
        inp.append(f"{r} {c}")
inp = '\n'.join(inp) + '\n'
out = subprocess.run(['./Itest'], input=inp, capture_output=True, text=True)
got = out.stdout.strip('\n').split('\n')
bad = 0
for k, ((n, m, g, imp), exp) in enumerate(zip(tests, expected)):
    gl = got[k].split() if got[k].strip() else []
    el = [str(x) for x in exp]
    if gl != el:
        bad += 1
        print('MISMATCH', k, 'got', gl, 'exp', el, 'grid', n, m, g, 'imp', imp)
        if bad > 4: sys.exit(1)
print('I checked', len(tests), 'bad', bad)
