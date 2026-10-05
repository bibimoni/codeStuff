import functools
def solve(n):
    @functools.lru_cache(None)
    def win(p):
        for k in range(2,10):
            if p*k >= n: return True
            if not win(p*k): return True
        return False
    return win(1)
ns=[int(x) for x in open('/tmp/din.txt').read().split()[1:]]
outs=open('/tmp/dout.txt').read().splitlines()
print(len(ns), len(outs))
bad=0
for n,o in zip(ns,outs):
    exp = "La premiere joueuse gagne." if (solve(n) if n>1 else True) else "La deuxieme joueuse gagne."
    if exp!=o: bad+=1; print("MISMATCH",n,exp,o)
print("checked",len(ns),"bad",bad)
