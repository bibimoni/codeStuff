import heapq, itertools, random, subprocess, sys

def dijkstra(a, k):
    n = len(a)
    start = tuple(a)
    INF = float('inf')
    dist = {start: 0}
    pq = [(0, start)]
    best = INF
    def has_win(s):
        run = 0
        for v in s:
            run = run + 1 if v == 0 else 0
            if run >= k: return True
        return False
    while pq:
        d, s = heapq.heappop(pq)
        if d != dist[s]: continue
        if has_win(s):
            return d
        # pay
        for i in range(n):
            for c in range(1, s[i] + 1):
                t = list(s); t[i] -= c
                t = tuple(t)
                nd = d + c
                if nd < dist.get(t, INF):
                    dist[t] = nd; heapq.heappush(pq, (nd, t))
        # rake
        for l in range(n):
            for m in range(l + 1, n):
                for r in range(m + 1, n):
                    v = max(s[l], s[r])
                    if v == s[m]: continue
                    t = list(s); t[m] = v
                    t = tuple(t)
                    if d < dist.get(t, INF):
                        dist[t] = d; heapq.heappush(pq, (d, t))
    return None

def formula(a, k):
    n = len(a)
    if k == 1:
        return min(a)
    suff = [0] * n
    suff[-1] = a[-1]
    for i in range(n - 2, -1, -1):
        suff[i] = min(a[i], suff[i + 1])
    best = None
    for L in range(n - k + 1):
        cand = a[L] + suff[L + k - 1]
        best = cand if best is None else min(best, cand)
    return best

random.seed(5)
bad = 0
tests = 0
for trial in range(400):
    n = random.randint(1, 6)
    k = random.randint(1, n)
    a = [random.randint(1, 3) for _ in range(n)]
    exp = dijkstra(a, k)
    got = formula(a, k)
    tests += 1
    if exp is None or got != exp:
        bad += 1
        print('MISMATCH n', n, 'k', k, 'a', a, 'dij', exp, 'formula', got)
        if bad > 5: sys.exit(1)
print('K checked', tests, 'bad', bad)
