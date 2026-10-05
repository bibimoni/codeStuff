import random, subprocess
random.seed(97)
def minsimple(n,a,b,s,t):
    adj={}
    for i in range(1,n+1):
        j=i%n+1
        adj.setdefault(i,[]).append((j,a[i])); adj.setdefault(j,[]).append((i,a[i]))
        adj.setdefault(i,[]).append((n+1,b[i])); adj.setdefault(n+1,[]).append((i,b[i]))
    best=[10**18]
    def dfs(u,cost,vis):
        if u==t: best[0]=min(best[0],cost); return
        for (v,w) in adj.get(u,[]):
            if v not in vis: vis.add(v); dfs(v,cost+w,vis); vis.discard(v)
    dfs(s,0,{s})
    return -1 if best[0]==10**18 else best[0]
cases=[];exps=[]
for _ in range(200):
    n=random.randint(2,4)
    a=[0]+[random.randint(-3,3) for _ in range(n)]
    b=[0]+[random.randint(-3,3) for _ in range(n)]
    ev=[]; A=a[:]; B=b[:]; out=[]
    for _ in range(random.randint(2,5)):
        r=random.random()
        if r<0.4:
            s=random.randint(1,n+1); t=random.randint(1,n+1)
            if s==t: continue
            if s>t: s,t=t,s
            ev.append((1,s,t)); out.append(minsimple(n,A,B,s,t))
        elif r<0.7:
            x=random.randint(1,n); w=random.randint(-3,3)
            ev.append((2,x,w)); A[x]=w
        else:
            x=random.randint(1,n); w=random.randint(-3,3)
            ev.append((3,x,w)); B[x]=w
    if not out: continue
    cases.append((n,a,b,ev)); exps.append(out)
inp=str(len(cases))+"\n"
for (n,a,b,ev) in cases:
    inp+=f"{n} {len(ev)}\n"+" ".join(map(str,a[1:]))+"\n"+" ".join(map(str,b[1:]))+"\n"
    for e in ev: inp+=" ".join(map(str,e))+"\n"
r=subprocess.run(["./l"],input=inp,capture_output=True,text=True)
got=[int(x) for x in r.stdout.strip().split("\n")]
i=0; bad=0
for ci,ex in enumerate(exps):
    for qi,w in enumerate(ex):
        if i<len(got) and got[i]!=w:
            print("case",ci,cases[ci],"qidx",qi,"got",got[i],"want",w); bad+=1
            if bad>2: break
        i+=1
    if bad>2: break
print("L UPDATE mismatches:",bad,"total queries",len(got))
