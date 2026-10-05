import subprocess, sys, random, itertools
random.seed(99)
def sh(binp, inp):
    return subprocess.run([binp], input=inp, capture_output=True, text=True).stdout

# ---------- K: brute force by simulating operations (closure on zero set) ----------
def bf_K(a, k):
    n = len(a)
    best = 10**9
    for mask in range(1 << n):
        paid = [i for i in range(n) if (mask >> i) & 1]
        cost = sum(a[i] for i in paid)
        if cost >= best: continue
        Z = set(paid)                      # set of zeroed positions
        changed = True
        while changed:                      # a zero can appear only between two zeros
            changed = False
            for m in range(n):
                if m in Z: continue
                if any(l in Z and r in Z for l in range(m) for r in range(m+1, n)):
                    Z.add(m); changed = True
        run = br = 0
        for i in range(n):
            run = run+1 if i in Z else 0
            br = max(br, run)
        if br >= k: best = min(best, cost)
    return best

bad = 0
cases = []
for _ in range(250):
    n = random.randint(1, 6)
    a = [random.randint(1, 4) for _ in range(n)]
    k = random.randint(1, n)
    cases.append((n, k, a))
inp = str(len(cases)) + "\n" + "".join(f"{n} {k}\n{' '.join(map(str,a))}\n" for n,k,a in cases)
out = sh("./K", inp).strip().split("\n")
for (n,k,a), o in zip(cases, out):
    e = bf_K(a, k)
    if int(o) != e:
        print("K MISMATCH", n, k, a, o, e); bad += 1
        if bad > 5: sys.exit(1)
print("K ok" if bad == 0 else "K FAILED")

# ---------- M: brute force permutations ----------
def invs(p):
    return sum(1 for i in range(len(p)) for j in range(i+1, len(p)) if p[i] > p[j])
bad = 0
cases = []
for n in range(1, 8):
    for _ in range(6):
        cases.append((n, random.randint(0, n*(n-1)//2), random.randint(1, 50)))
inp = str(len(cases)) + "\n" + "".join(f"{n} {m} {k}\n" for n,m,k in cases)
out = sh("./M", inp).strip().split("\n")
for (n,m,k), o in zip(cases, out):
    lst = [p for p in itertools.permutations(range(1, n+1)) if invs(p) == m]
    lst.sort()
    e = " ".join(map(str, lst[k-1])) if k <= len(lst) else "-1"
    if o != e:
        print("M MISMATCH", n, m, k, o, "|", e); bad += 1
        if bad > 5: sys.exit(1)
print("M ok" if bad == 0 else "M FAILED")
