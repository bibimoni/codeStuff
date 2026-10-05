import random, itertools, sys

MOD = 998244353

def solve_E(n, edges):
    # edges: (u,v,w) 0-indexed, w in {0,1,2}
    # Build tree adjacency with direction relative to root
    adj = [[] for _ in range(n)]
    for u, v, w in edges:
        adj[u].append((v, w))
        adj[v].append((u, w))
    par = [-1]*n
    parw = [0]*n  # direction of edge to parent: 0 free, 1 = parent before me, 2 = me before parent
    order = []
    root = 0
    par[root] = root
    stack = [root]
    seen = [False]*n
    seen[root] = True
    while stack:
        v = stack.pop()
        order.append(v)
        for to, w in adj[v]:
            if seen[to]: continue
            seen[to] = True
            par[to] = v
            # relation between v (parent) and to (child)
            if w == 0:
                parw[to] = 0            # free
            else:
                # w=1 means "first of pair before second". If edge was (v,to,1) => v before to.
                # We stored w symmetrically; need order info.
                pass
            stack.append(to)
    # recompute direction properly using original edge order
    # For each node c != root with parent p, find the original (a,b,w) with {a,b}={p,c}
    dirbefore = [0]*n  # dirbefore[c]=1 => c before p (i.e., c->p); 0 => p before c; 2 free
    for u, v, w in edges:
        for (a, b) in [(u, v), (v, u)]:
            pass
    # simpler: for each edge (u,v,w): if w=1 then u->v ; if w=2 then v->u
    # store as set of directed relations
    rel = {}
    for u, v, w in edges:
        if w == 1: rel[frozenset((u, v))] = (u, v)   # u before v
        elif w == 2: rel[frozenset((u, v))] = (v, u) # v before u
    for c in range(n):
        if c == root: continue
        p = par[c]
        if frozenset((p, c)) not in rel:
            dirbefore[c] = 2  # free
        else:
            a, b = rel[frozenset((p, c))]  # a before b
            dirbefore[c] = 1 if (a == c) else 0  # c before p if c==a else p before c
    sys.setrecursionlimit(10**6)
    # children lists in original tree
    ch = [[] for _ in range(n)]
    for c in range(n):
        if c != root: ch[par[c]].append(c)
    # factorials for binomials up to n
    fact = [1]*(n+1)
    for i in range(1, n+1): fact[i] = fact[i-1]*i % MOD
    ifact = [1]*(n+1)
    ifact[n] = pow(fact[n], MOD-2, MOD)
    for i in range(n, 0, -1): ifact[i-1] = ifact[i]*i % MOD
    def C(a, b):
        if b < 0 or b > a: return 0
        return fact[a]*ifact[b] % MOD * ifact[a-b] % MOD
    sz = [0]*n
    f = [None]*n
    def dfs(v):
        acc = [1]  # just v, v at position 0
        s = 1
        for c in ch[v]:
            dfs(c)
            b = sz[c]
            fc = f[c]
            Wc = sum(fc) % MOD
            # R[t]
            R = [0]*(b+1)
            d = dirbefore[c]
            if d == 1:   # c before v: prefix includes c => c at position < t
                pre = 0
                for t in range(b+1):
                    R[t] = pre
                    if t < b: pre = (pre + fc[t]) % MOD
            elif d == 0: # v before c: prefix excludes c => c at position >= t
                for t in range(b-1, -1, -1):
                    R[t] = (R[t+1] + fc[t]) % MOD   # R[b]=0, R[t]=sum_{i>=t} fc[i]
            else:        # free
                for t in range(b+1): R[t] = Wc
            new = [0]*(s+b)
            for k in range(s):
                if acc[k] == 0: continue
                base = acc[k]
                for t in range(b+1):
                    if R[t] == 0: continue
                    val = base * R[t] % MOD
                    val = val * C(k+t, k) % MOD
                    val = val * C(s-1-k+b-t, s-1-k) % MOD
                    new[k+t] = (new[k+t] + val) % MOD
            acc = new
            s += b
        f[v] = acc
        sz[v] = s
    dfs(root)
    return sum(f[root]) % MOD

def brute(n, edges):
    cons = []
    for u, v, w in edges:
        if w == 1: cons.append((u, v))
        elif w == 2: cons.append((v, u))
    cnt = 0
    for p in itertools.permutations(range(n)):
        pos = {x: i for i, x in enumerate(p)}
        if all(pos[a] < pos[b] for a, b in cons): cnt += 1
    return cnt

def rand_tree(n, R):
    edges = []
    for v in range(1, n):
        p = R.randrange(v)
        w = R.choice([0, 1, 2])
        edges.append((p, v, w))
    return edges

R = random.Random(int(sys.argv[1]) if len(sys.argv) > 1 else 0)
bad = 0
for it in range(2000):
    n = R.randint(1, 8)
    edges = rand_tree(n, R)
    b = brute(n, edges)
    s = solve_E(n, edges)
    if b != s:
        bad += 1
        if bad <= 6:
            print("MISMATCH n", n, "edges", edges, "brute", b, "dp", s)
print("mismatches:", bad, "/2000")
