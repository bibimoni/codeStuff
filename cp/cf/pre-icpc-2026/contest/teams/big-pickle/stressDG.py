import subprocess, sys, random
from functools import lru_cache
random.seed(7)

def sh(binp, inp):
    return subprocess.run([binp], input=inp, capture_output=True, text=True).stdout

# ---------- D: memoized game DP (exact) ----------
from math import gcd
def brute_D(n):
    # state = (p, n) ; current player to move at p ; returns True if wins
    from functools import lru_cache
    @lru_cache(maxsize=None)
    def win(p, n):
        for k in range(2, 10):
            if p*k >= n: return True
            if not win(p*k, n): return True
        return False
    return win(1, n)

bad = 0
ns = list(range(1, 400)) + [random.randint(1, 10**9) for _ in range(400)] + \
     [18**i for i in range(1, 9)] + [9*18**i for i in range(0, 8)] + \
     [18**i - 1 for i in range(1, 9)] + [9*18**i - 1 for i in range(0, 8)] + [10**9]
ns = [x for x in ns if 1 <= x <= 10**9]
inp = str(len(ns)) + "\n" + "\n".join(map(str, ns)) + "\n"
out = sh("./D", inp).strip().split("\n")
for n, o in zip(ns, out):
    exp = "La premiere joueuse gagne." if brute_D(n) else "La deuxieme joueuse gagne."
    if o != exp:
        print("D MISMATCH", n, o, exp); bad += 1
        if bad > 5: sys.exit(1)
print("D ok" if bad == 0 else "D FAILED")

# ---------- G: brute force all-pairs ----------
def bf_G(d):
    n = len(d)
    dx = [0,-1,0,1]; dy = [1,0,-1,0]
    pts = [(0,0)]
    for i in range(n):
        x,y = pts[-1]
        pts.append((x+dx[i%4]*d[i], y+dy[i%4]*d[i]))
    def hit(Aa,Bb):
        (x1,y1),(x2,y2) = Aa; (x3,y3),(x4,y4) = Bb
        # generic segment intersection (cross products), touch counts
        def cr(o,a,b): return (a[0]-o[0])*(b[1]-o[1]) - (a[1]-o[1])*(b[0]-o[0])
        d1 = cr((x1,y1),(x2,y2),(x3,y3)); d2 = cr((x1,y1),(x2,y2),(x4,y4))
        d3 = cr((x3,y3),(x4,y4),(x1,y1)); d4 = cr((x3,y3),(x4,y4),(x2,y2))
        def on(p,q,r): return cr(p,q,r)==0 and min(p[0],q[0])<=r[0]<=max(p[0],q[0]) and min(p[1],q[1])<=r[1]<=max(p[1],q[1])
        if ((d1>0)!=(d2>0) or (d1<0)!=(d2<0)) and ((d3>0)!=(d4>0) or (d3<0)!=(d4<0)):
            if d1!=0 and d2!=0 and d3!=0 and d4!=0: return True
        if d1==0 and on((x1,y1),(x2,y2),(x3,y3)): return True
        if d2==0 and on((x1,y1),(x2,y2),(x4,y4)): return True
        if d3==0 and on((x3,y3),(x4,y4),(x1,y1)): return True
        if d4==0 and on((x3,y3),(x4,y4),(x2,y2)): return True
        return False
    for i in range(n):
        for j in range(i+2, n):
            if hit((pts[i],pts[i+1]),(pts[j],pts[j+1])): return "Yes"
    return "No"

bad = 0
cases = []
for _ in range(400):
    n = random.randint(1, 9)
    cases.append([random.randint(1,6) for _ in range(n)])
for _ in range(200):
    n = random.randint(4, 9)
    cases.append([random.choice([1,2,3,1,1,4]) for _ in range(n)])
inp = str(len(cases)) + "\n" + "".join(f"{len(c)}\n{' '.join(map(str,c))}\n" for c in cases)
out = sh("./G", inp).strip().split("\n")
for c, o in zip(cases, out):
    e = bf_G(c)
    if o != e:
        print("G MISMATCH", c, o, e); bad += 1
        if bad > 5: sys.exit(1)
print("G ok" if bad == 0 else "G FAILED")
