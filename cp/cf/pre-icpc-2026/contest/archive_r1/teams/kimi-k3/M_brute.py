import itertools, sys
def inv(p): return sum(1 for i in range(len(p)) for j in range(i+1,len(p)) if p[i]>p[j])
data = sys.stdin.read().split()
t = int(data[0]); idx = 1
out = []
for _ in range(t):
    n,m,k = int(data[idx]),int(data[idx+1]),int(data[idx+2]); idx+=3
    ps = [p for p in itertools.permutations(range(1,n+1)) if inv(p)==m]
    ps.sort()
    out.append(' '.join(map(str,ps[k-1])) if k<=len(ps) else '-1')
print('\n'.join(out))
