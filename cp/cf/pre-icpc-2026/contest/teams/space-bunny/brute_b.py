import random, subprocess, sys
random.seed(int(sys.argv[1]) if len(sys.argv)>1 else 9)
NC = 150
cases=[];exps=[]
for _ in range(NC):
    n=random.randint(1,8)
    edges=[]
    for u in range(1,n+1):
        for v in range(u+1,n+1):
            if random.random()<0.35: edges.append((u,v))
    q=random.randint(1,4)
    states=[''.join(random.choice('01') for _ in range(n)) for _ in range(q)]
    sep = random.choice(['','',' '])   # sometimes spaced like the sample
    stlines=[sep.join(s) if sep else s for s in states]
    lines=[f"{n} {len(edges)} {q}"]+[f"{u} {v}" for u,v in edges]+stlines
    cur=[]
    for s in states:
        b=[1 if c=='0' else 0 for c in s]
        sol=None
        for x in range(1<<n):
            res=b[:]
            for i in range(n):
                if (x>>i)&1:
                    res[i]^=1
                    for (u,v) in edges:
                        if u-1==i: res[v-1]^=1
                        if v-1==i: res[u-1]^=1
            if all(r==0 for r in res): sol=x; break
        if sol is None: cur.append("-1")
        else:
            ks=[str(i+1) for i in range(n) if (sol>>i)&1]
            cur.append(str(len(ks))+(" "+" ".join(ks) if ks else ""))
    cases.append("\n".join(lines)); exps.append(cur)
ok=0
for c,ex in zip(cases,exps):
    r=subprocess.run(["./b"],input=c+"\n",capture_output=True,text=True)
    lines=[l.split() for l in r.stdout.strip().split("\n")]
    if len(lines)!=len(ex):
        print("LINECOUNT",lines,ex); break
    bad=False
    for got,want in zip(lines,ex):
        if want=="-1":
            if got!=["-1"]: bad=True
        else:
            w=want.split()
            if got[0]!=w[0] or set(got[1:])!=set(w[1:]): bad=True
    if bad:
        print("FAIL\n"+c+"\ngot:\n"+r.stdout+"\nwant:\n"+"\n".join(ex)); break
    ok+=1
print("B STRESS:",ok,"/",len(cases))
