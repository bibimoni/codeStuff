import random, subprocess
random.seed(int(__import__('sys').argv[1]) if len(__import__('sys').argv)>1 else 5)
def minsimple(n,a,b,s,t):
    # nodes 1..n plus hub n+1 ; DFS all simple paths
    adj={}
    for i in range(1,n+1):
        j=i%n+1
        adj.setdefault(i,[]).append((j,a[i]))
        adj.setdefault(j,[]).append((i,a[i]))
        adj.setdefault(i,[]).append((n+1,b[i]))
        adj.setdefault(n+1,[]).append((i,b[i]))
    best=[10**18]
    def dfs(u,cost,vis):
        if u==t:
            best[0]=min(best[0],cost); return
        for (v,w) in adj.get(u,[]):
            if v not in vis:
                vis.add(v); dfs(v,cost+w,vis); vis.discard(v)
    dfs(s,0,{s})
    return -1 if best[0]==10**18 else best[0]
NC=250
cases=[];exps=[]
for _ in range(NC):
    n=random.randint(2,6)
    a=[0]+[random.randint(-6,6) for _ in range(n)]
    b=[0]+[random.randint(-6,6) for _ in range(n)]
    q=random.randint(1,8)
    ev=[]
    for _ in range(q):
        r=random.random()
        if r<0.55:
            s=random.randint(1,n+1); t=random.randint(1,n+1)
            if s==t: continue
            if s>t: s,t=t,s
            ev.append((1,s,t))
        elif r<0.8:
            ev.append((2,random.randint(1,n),random.randint(-6,6)))
        else:
            ev.append((3,random.randint(1,n),random.randint(-6,6)))
    if not ev: continue
    cases.append((n,a,b,ev))
inp=str(len(cases))+"\n"
exps=[]
for (n,a,b,ev) in cases:
    inp+=f"{n} {len(ev)}\n"+" ".join(map(str,a[1:]))+"\n"+" ".join(map(str,b[1:]))+"\n"
    for e in ev:
        if e[0]==1: inp+=f"1 {e[1]} {e[2]}\n"
        elif e[0]==2: inp+=f"2 {e[1]} {e[2]}\n"
        else: inp+=f"3 {e[1]} {e[2]}\n"
    # simulate
    A=a[:]; B=b[:]
    out=[]
    for e in ev:
        if e[0]==2: A[e[1]]=e[2]
        elif e[0]==3: B[e[1]]=e[2]
        else: out.append(minsimple(n,A,B,e[1],e[2]))
    exps.append(out)
r=subprocess.run(["./l"],input=inp,capture_output=True,text=True)
got=[int(x) for x in r.stdout.strip().split("\n")] if r.stdout.strip() else []
flat=[x for o in exps for x in o]
bad=0
for i,(g,w) in enumerate(zip(got,flat)):
    if g!=w:
        print("MISMATCH at",i,"got",g,"want",w)
        # find the case
        cnt=0
        for ci,ex in enumerate(exps):
            if i<cnt+len(ex): print("case",ci,cases[ci]); break
            cnt+=len(ex)
        bad+=1
        if bad>2: break
print("L STRESS:", "OK" if not bad else "FAIL", len(got),"vs",len(flat))
