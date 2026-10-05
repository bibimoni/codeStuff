import sys,random
def rref(A,n):
    rows=[A[i]|(1<<(n+i)) for i in range(n)]
    r=0;piv=[]
    for c in range(n):
        p=-1
        for i in range(r,n):
            if (rows[i]>>c)&1: p=i;break
        if p<0: continue
        rows[r],rows[p]=rows[p],rows[r]
        pr=rows[r]
        for i in range(n):
            if i!=r and ((rows[i]>>c)&1): rows[i]^=pr
        piv.append(c); r+=1
    L=[x&((1<<n)-1) for x in rows]; E=[x>>n for x in rows]
    return r,piv,L,E
def mv(M,v,n):   # M rows bitmasks, v bitmask
    s=0
    for i in range(n):
        if (M[i])&((1<<n)-1)==0: continue
        t=0; mm=M[i]
        for j in range(n):
            if (mm>>j)&1: t^=(v>>j)&1
        s|=0
        s=(s&~0)
        s=t if False else s
        s=s^t if False else s
        s=(s^t) if False else s
        s=s
        s=(s^t) if False else 0
        s=s^t
    return s
def mvx(M,v,n):
    s=0
    for i in range(n):
        t=0
        for j in range(n):
            if (M[i]>>j)&1: t^=(v>>j)&1
        s^=t
    return s
def solve(A,b,n):
    r,piv,L,E=rref(A,n)
    y=mvx(E,b,n)
    if y>>r: return None
    x=0
    for j,c in enumerate(piv):
        if (y>>j)&1: x|=1<<c
    return x
if __name__=="__main__":
    n=7
    edges=[(1,2),(1,3),(2,4),(2,5),(3,5),(3,6),(4,7),(5,7),(6,7)]
    A=[1<<i for i in range(n)]
    for u,v in edges:
        A[u-1]^=1<<(v-1); A[v-1]^=1<<(u-1)
    s=[int(c) for c in "1011001"]
    b=0
    for i in range(n): b|=(1-s[i])<<i
    print("b=",bin(b))
    x=solve(A,b,n); print("x=",bin(x) if x is not None else None)
    # verify
    if x is not None:
        ok=all((lambda t: t==(1-s[i]))(mvx(A,x,n)) for i in range(n))
        print("verify A x == b:", mvx(A,x,n)==b)
