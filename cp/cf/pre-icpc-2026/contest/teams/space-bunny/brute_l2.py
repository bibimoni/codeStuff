import random, subprocess
random.seed(41)
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
for _ in range(400):
    n=random.randint(2,6)
    a=[0]+[random.randint(-4,4) for _ in range(n)]
    b=[0]+[random.randint(-4,4) for _ in range(n)]
    qs=[]
    for s in range(1,n+2):
        for t in range(s+1,n+2):
            qs.append((s,t))
    random.shuffle(qs); qs=qs[:6]
    cases.append((n,a,b,qs))
    exps.append([minsimple(n,a,b,s,t) for s,t in qs])
inp=str(len(cases))+"\n"
for (n,a,b,qs) in cases:
    inp+=f"{n} {len(qs)}\n"+" ".join(map(str,a[1:]))+"\n"+" ".join(map(str,b[1:]))+"\n"
    for s,t in qs: inp+=f"1 {s} {t}\n"
r=subprocess.run(["./l"],input=inp,capture_output=True,text=True)
got=[int(x) for x in r.stdout.strip().split("\n")]
flatq=[]
idx=0
for ci,ex in enumerate(exps):
    for qi,w in enumerate(ex):
        if idx<len(got) and got[idx]!=w: flatq.append((idx,got[idx],w,ci,cases[ci][3][qi]))
        idx+=1
flat=flatq
print("L QUERY-ONLY mismatches:",len(flat),"of",len(got))
for f in flat[:4]:
    print("idx",f[0],"got",f[1],"want",f[2],"case",f[3],"q",f[4])
