import subprocess, sys, random
from collections import OrderedDict
random.seed(555)
def sh(binp, inp):
    return subprocess.run([binp], input=inp, capture_output=True, text=True).stdout

# ================= H: brute force LRU with a plain OrderedDict =================
def bf_H(n, ops):
    # cache: key -> value, ordered LRU..MRU  (OrderedDict.move_to_end keeps MRU last)
    od = OrderedDict((i, 0) for i in range(1, n+1))
    res = []
    for op in ops:
        if op[0] == 1:
            _, a, b = op
            if a in od: od[a] = b; od.move_to_end(a)
            else: od[a] = b; od.move_to_end(a)
            if len(od) > n: od.popitem(last=False)
        else:
            _, a = op
            if a not in od: res.append("-1")
            else:
                order = len(od) - list(od.keys()).index(a)   # 1 = MRU
                res.append(f"{od[a]} {order}")
                od.move_to_end(a)
    return res

bad = 0
cases = []
for _ in range(150):
    n = random.randint(1, 6)
    q = random.randint(1, 10)
    ops = []
    for _ in range(q):
        if random.random() < 0.5:
            ops.append((1, random.randint(1, 12), random.randint(1, 1000)))
        else:
            ops.append((2, random.randint(1, 12)))
    cases.append((n, ops))
inp = str(len(cases)) + "\n"
for n, ops in cases:
    inp += f"{n} {len(ops)}\n"
    for op in ops: inp += " ".join(map(str, op)) + "\n"
out = sh("./H", inp).split("\n")
i = 0
for n, ops in cases:
    exp = bf_H(n, ops)
    for e in exp:
        o = out[i]; i += 1
        if o != e:
            print("H MISMATCH", n, ops, o, e); bad += 1
            if bad > 5: sys.exit(1)
print("H ok" if bad == 0 else "H FAILED")

# ================= I: brute force cycle count = E - V + C on tiny grids =================
def bf_I(n, m, g, hits):
    def state(k):
        gg = [0 if i in k else v for i, v in enumerate(g)]
        E = 0
        for i in range(n):
            for j in range(m):
                u = i*m+j
                if gg[u] == 0: continue
                if j+1 < m and gg[u+1] != 0 and (gg[u] & 2) and (gg[u+1] & 8): E += 1
                if i+1 < n and gg[u+m] != 0 and (gg[u] & 4) and (gg[u+m] & 1): E += 1
        par = list(range(n*m))
        def f(a):
            while par[a] != a: par[a] = par[par[a]]; a = par[a]
            return a
        for i in range(n):
            for j in range(m):
                u = i*m+j
                if gg[u] == 0: continue
                if j+1 < m and gg[u+1] != 0 and (gg[u] & 2) and (gg[u+1] & 8):
                    par[f(u)] = f(u+1)
                if i+1 < n and gg[u+m] != 0 and (gg[u] & 4) and (gg[u+m] & 1):
                    par[f(u)] = f(u+m)
        V = sum(1 for v in gg if v != 0)
        C = len({f(i) for i in range(n*m) if gg[i] != 0})
        return E - V + C
    cur = set(hits); res = []
    for h in hits:
        cur = cur | {h}
        res.append(state(cur))
    return res

bad = 0
cases = []
for _ in range(250):
    n = random.randint(1, 3); m = random.randint(1, 3)
    g = [random.choice([0,0,0,3,5,6,7,9,10,11,12,13,14,15]) for _ in range(n*m)]
    jn = [i for i in range(n*m) if g[i] != 0]
    if not jn: continue
    k = random.randint(0, len(jn))
    hits = random.sample(jn, k)
    cases.append((n, m, g, hits))
inp = str(len(cases)) + "\n"
for n, m, g, hits in cases:
    inp += f"{n} {m}\n"
    for i in range(n): inp += " ".join(map(str, g[i*m:(i+1)*m])) + "\n"
    inp += f"{len(hits)}\n"
    for i, h in enumerate(hits): inp += f"{h//m+1} {h%m+1}\n"
out = sh("./I", inp).split("\n")
i = 0
for n, m, g, hits in cases:
    o = out[i].strip(); i += 1
    if not hits:
        if o != "": print("I MISMATCH empty line", repr(out[i-1])); bad += 1
        continue
    exp = " ".join(map(str, bf_I(n, m, g, hits)))
    if o != exp:
        print("I MISMATCH", n, m, g, hits, o, exp); bad += 1
        if bad > 5: sys.exit(1)
print("I ok" if bad == 0 else "I FAILED")
