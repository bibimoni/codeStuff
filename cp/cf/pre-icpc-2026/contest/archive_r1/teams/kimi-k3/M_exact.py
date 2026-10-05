import sys
def solve(n,m,k):
    rows={0:[1]}
    row=[1]
    for nn in range(1, n+1):
        ln=nn*(nn-1)//2
        nxt=[0]*(ln+1)
        win=0
        for mm in range(ln+1):
            win += row[mm] if mm < len(row) else 0
            if mm-nn>=0: win -= row[mm-nn]
            nxt[mm]=win
        row=nxt; rows[nn]=row
    def C(nn,mm):
        if mm<0: return 0
        r=rows[nn]; return r[mm] if mm<len(r) else 0
    if C(n,m)<k: return "-1"
    avail=list(range(1,n+1)); rem=m; out=[]
    for pos in range(n):
        nn=n-pos
        for c in range(len(avail)):
            if c>rem: break
            w=C(nn-1,rem-c)
            if k>w: k-=w; continue
            out.append(avail.pop(c)); rem-=c; break
    return ' '.join(map(str,out))
data=sys.stdin.read().split(); t=int(data[0]); idx=1; res=[]
for _ in range(t):
    n,m,k=int(data[idx]),int(data[idx+1]),int(data[idx+2]); idx+=3
    res.append(solve(n,m,k))
print('\n'.join(res))
