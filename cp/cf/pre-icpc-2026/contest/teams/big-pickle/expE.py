import random, itertools, sys
from functools import lru_cache

def brute(n, edges):
    # edges: list of (u,v,w) 0-indexed. Count permutations respecting w=1,2 constraints.
    cons = []
    for u,v,w in edges:
        if w==1: cons.append((u,v))   # u before v
        elif w==2: cons.append((v,u)) # v before u
    cnt=0
    for p in itertools.permutations(range(n)):
        pos={x:i for i,x in enumerate(p)}
        if all(pos[a]<pos[b] for a,b in cons): cnt+=1
    return cnt

def hook(n, edges):
    # poset-forest: parent(c)= the node forced before c. Tree hook-length.
    par=[-1]*n
    for u,v,w in edges:
        if w==1: par[v]=u
        elif w==2: par[u]=v
    # detect multi-parent
    cnt=[0]*n
    for c in range(n):
        if par[c]>=0: cnt[c]+=1
    multi=any(c>1 for c in cnt)
    # sizes via children
    ch=[[] for _ in range(n)]
    for c in range(n):
        if par[c]>=0: ch[par[c]].append(c)
    sys.setrecursionlimit(10**6)
    size=[0]*n
    def dfs(v):
        size[v]=1
        for c in ch[v]: size[v]+=dfs(c)
        return size[v]
    roots=[v for v in range(n) if par[v]<0]
    for r in roots: dfs(r)
    prod=1
    for v in range(n): prod=prod*size[v]
    from math import factorial
    return factorial(n)//prod, multi

random.seed(int(sys.argv[1]) if len(sys.argv)>1 else 0)
bad=0
for it in range(400):
    n=random.randint(2,7)
    # random tree
    par=list(range(n))
    import random as R
    def find(x):
        while par[x]!=x: par[x]=par[par[x]]; x=par[x]
        return x
    edges=[]
    for v in range(1,n):
        p=R.randrange(v)
        w=R.choice([0,1,2])
        edges.append((p,v,w))
    b=brute(n,edges)
    h,multi=hook(n,edges)
    if b!=h:
        bad+=1
        if bad<=8: print("MISMATCH n",n,"edges",edges,"brute",b,"hook",h,"multi-parent",multi)
print("mismatches:",bad,"/400")
