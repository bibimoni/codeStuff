import subprocess, random, sys

INF = float('inf')

def min_simple_path(n, a, b, s, t):
    # nodes: 0..n-1 islands, n = nook. a[i] connects i and (i+1)%n (a indexed 1..n: a[i] edge (i, i%n+1))
    # b[i] connects island i with nook
    # s,t 1-based; t can be n+1 (nook)
    adj = [[] for _ in range(n + 1)]
    for i in range(n):
        j = (i + 1) % n
        adj[i].append((j, a[i]))
        adj[j].append((i, a[i]))
    for i in range(n):
        adj[i].append((n, b[i]))
        adj[n].append((i, b[i]))
    src, dst = s - 1, t - 1
    best = [INF]
    def dfs(u, cost, vis):
        if u == dst:
            if cost < best[0]: best[0] = cost
            return
        for v, w in adj[u]:
            if not (vis >> v) & 1:
                dfs(v, cost + w, vis | (1 << v))
    dfs(src, 0, 1 << src)
    return best[0]

def run_case(n, events, a, b):
    # build input, run Ltest, compute expected for each type-1 with current state
    lines = ["1", f"{n} {len(events)}"]
    lines.append(' '.join(map(str, a)))
    lines.append(' '.join(map(str, b)))
    for ev in events:
        lines.append(' '.join(map(str, ev)))
    inp = '\n'.join(lines) + '\n'
    out = subprocess.run(['./Ltest'], input=inp, capture_output=True, text=True)
    got = out.stdout.split('\n')
    exp = []
    aa, bb = list(a), list(b)
    for ev in events:
        if ev[0] == 1:
            exp.append(str(min_simple_path(n, aa, bb, ev[1], ev[2])))
        elif ev[0] == 2:
            aa[ev[1] - 1] = ev[2]
        else:
            bb[ev[1] - 1] = ev[2]
    bad = 0
    for i, e in enumerate(exp):
        if got[i] != e:
            bad += 1
            print('MISMATCH exp', e, 'got', got[i], 'n', n, 'case', i)
            if bad > 5: return bad
    # leftover check
    if len([g for g in got if g.strip()]) != len(exp):
        bad += 1
        print('LINE COUNT', len(got), len(exp))
    return bad

random.seed(42)
total = 0
bad = 0
for trial in range(120):
    n = random.randint(2, 7)
    a = [random.randint(-5, 5) for _ in range(n)]
    b = [random.randint(-5, 5) for _ in range(n)]
    events = []
    for _ in range(random.randint(1, 12)):
        r = random.random()
        if r < 0.6:
            s = random.randint(1, n)
            t = random.randint(s + 1, n + 1)
            events.append((1, s, t))
        elif r < 0.8:
            events.append((2, random.randint(1, n), random.randint(-5, 5)))
        else:
            events.append((3, random.randint(1, n), random.randint(-5, 5)))
    bad += run_case(n, events, a, b)
    total += sum(1 for e in events if e[0] == 1)
    if bad > 5: break
print('L checked', total, 'queries, bad', bad)
sys.exit(1 if bad else 0)
