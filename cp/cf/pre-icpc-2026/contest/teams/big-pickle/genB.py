import random, sys
random.seed(int(sys.argv[2]))
T=int(sys.argv[1]); out=[str(T)]
for _ in range(T):
    N=random.randint(1,12); maxe=N*(N-1)//2
    M=random.randint(0,min(maxe,20))
    edges=set()
    style=random.random()
    if style<0.5:
        for i in range(1,N): edges.add((random.randrange(i),i))
    while len(edges)<M:
        u=random.randrange(N); v=random.randrange(N)
        if u!=v: edges.add((min(u,v),max(u,v)))
    edges=sorted(edges)[:M]
    Q=random.randint(1,5)
    out.append(f"{N} {len(edges)} {Q}")
    for u,v in edges: out.append(f"{u+1} {v+1}")
    for _ in range(Q):
        sep = ' ' if random.random()<0.5 else ''
        out.append(sep.join(str(random.randrange(2)) for _ in range(N)))
print("\n".join(out))
