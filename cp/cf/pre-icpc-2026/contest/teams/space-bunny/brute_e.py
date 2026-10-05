import random, itertools, subprocess
random.seed(31)
tests=[];exp=[]
for _ in range(400):
    n=random.randint(1,8)
    # random tree
    perm=list(range(n)); random.shuffle(perm)
    par=[-1]+perm[1:]
    edges=[]
    for v in range(1,n):
        u=par[v]
        if random.random()<0.5: edges.append((u+1,v+1,random.choice([0,1,2])))
        else: edges.append((v+1,u+1,random.choice([0,1,2])))
    # expected: sum over orientations of #topological orders
    flex=[i for i,e in enumerate(edges) if e[2]==0]
    tot=0
    for mask in range(1<<len(flex)):
        req={}
        for i,(u,v,w) in enumerate(edges):
            if w==0:
                bit=(mask>>flex.index(i))&1
                req[(u,v)]= 0 if bit==0 else 1   # 0: u before v, 1: v before u
            elif w==1: req[(u,v)]=0
            else: req[(u,v)]=1
        for p in itertools.permutations(range(1,n+1)):
            pos={x:i for i,x in enumerate(p)}
            if all((pos[u]<pos[v]) if d==0 else (pos[v]<pos[u]) for (u,v),d in req.items()): tot+=1
    tests.append(f"{n}\n"+"\n".join(f"{a} {b} {c}" for a,b,c in edges))
    exp.append(tot%998244353)
open('eb.txt','w').write(str(len(tests))+"\n"+"\n".join(tests)+"\n")
open('eb.exp','w').write("\n".join(map(str,exp))+"\n")
