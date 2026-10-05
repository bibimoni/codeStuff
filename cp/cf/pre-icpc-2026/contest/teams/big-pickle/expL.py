import random, sys, itertools
sys.setrecursionlimit(100000)
INF = float('inf')

# ---- brute force: min cost SIMPLE path from s to t (0..n; 0 = Nook) ----
def brute(n, a, b, s, t):
    # nodes: 1..n islands, 0 = Nook. causeway i (1..n): i <-> (i%n)+1, cost a[i]. flight i<->0 cost b[i].
    adj = {i: [] for i in range(0, n + 1)}
    for i in range(1, n + 1):
        j = i % n + 1
        adj[i].append((j, a[i])); adj[j].append((i, a[i]))
    for i in range(1, n + 1):
        adj[i].append((0, b[i])); adj[0].append((i, b[i]))
    best = [INF]
    def dfs(u, cost, visited):
        if u == t:
            best[0] = min(best[0], cost)
            return
        for v, w in adj[u]:
            if v in visited:
                continue
            visited.add(v)
            dfs(v, cost + w, visited)
            visited.remove(v)
    dfs(s, 0, {s})
    return best[0]

# ---- direct formula via the derived case decomposition ----
def minPair(A, V, l, r):
    best = INF
    for i in range(l, r + 1):
        for j in range(i + 1, r + 1):
            if A[i] + V[j] < best:
                best = A[i] + V[j]
    return best

def minA(A, l, r):
    if l > r: return INF
    return min(A[i] for i in range(l, r + 1))

def minV(V, l, r):
    if l > r: return INF
    return min(V[i] for i in range(l, r + 1))

def direct_islands(n, a, b, s, t):
    # P[i] = sum_{j<i} a[j], 1-indexed; C = total
    # P[i] = sum_{j=1}^{i-1} a[j]
    P = [0] * (n + 2)
    acc = 0
    for i in range(1, n + 2):
        P[i] = acc
        if i >= 1 and i <= n:
            acc += a[i]
    C = P[n + 1]
    A = [None] + [P[i] + b[i] for i in range(1, n + 1)]
    V = [None] + [b[i] - P[i] for i in range(1, n + 1)]
    D = P[t] - P[s]
    cands = []
    cands.append(min(D, C - D))                              # (0) pure ring
    cands.append(minPair(A, V, s, t) + D)                     # (1)
    cands.append(minA(A, s, t - 1) + minA(A, 1, s - 1) + C - P[s] - P[t])   # (2a)
    cands.append(minA(A, s, t - 1) + minA(A, t + 1, n) - P[s] - P[t])       # (2b)
    cands.append(minV(V, 1, s - 1) + minV(V, s + 1, t) + P[s] + P[t])       # (3a)
    cands.append(minV(V, t + 1, n) + minV(V, s + 1, t) + C + P[s] + P[t])   # (3b)
    cands.append(minV(V, 1, s - 1) + minA(A, t + 1, n) + P[s] - P[t])       # (4i)
    cands.append(minPair(A, V, 1, s - 1) + C + P[s] - P[t])                 # (4-lo)
    cands.append(minPair(A, V, t + 1, n) + C + P[s] - P[t])                 # (4-hi)
    return min(cands)

def direct_nook(n, a, b, s):
    P = [0] * (n + 2)
    acc = 0
    for i in range(1, n + 2):
        P[i] = acc
        if i <= n:
            acc += a[i]
    C = P[n + 1]
    A = [None] + [P[i] + b[i] for i in range(1, n + 1)]
    V = [None] + [b[i] - P[i] for i in range(1, n + 1)]
    cands = [b[s]]
    cands.append(minA(A, s + 1, n) - P[s])          # inc
    cands.append(minV(V, 1, s - 1) + P[s])          # dec
    cands.append(minV(V, s + 1, n) + P[s] + C)      # dec wrapping
    cands.append(minA(A, 1, s - 1) + C - P[s])      # inc wrapping
    return min(cands)

R = random.Random(int(sys.argv[1]) if len(sys.argv) > 1 else 0)
bad_isl = 0; bad_nook = 0
T = 4000
for it in range(T):
    n = R.randint(2, 7)
    a = [0] + [R.randint(-3, 3) for _ in range(n)]
    b = [0] + [R.randint(-3, 3) for _ in range(n)]
    s = R.randint(1, n)
    if R.random() < 0.5 and s < n:
        t = R.randint(s + 1, n)  # island-island with s<t
        bt = brute(n, a, b, s, t)
        dr = direct_islands(n, a, b, s, t)
        if bt != dr:
            bad_isl += 1
            if bad_isl <= 6:
                print("ISL MISMATCH n", n, "a", a[1:], "b", b[1:], "s", s, "t", t, "brute", bt, "direct", dr)
    else:
        t = 0  # Nook
        bt = brute(n, a, b, s, 0)
        dr = direct_nook(n, a, b, s)
        if bt != dr:
            bad_nook += 1
            if bad_nook <= 6:
                print("NOOK MISMATCH n", n, "a", a[1:], "b", b[1:], "s", s, "brute", bt, "direct", dr)
print("island mismatches:", bad_isl, " nook mismatches:", bad_nook, " total", T)
