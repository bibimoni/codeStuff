import subprocess, sys, itertools
from functools import lru_cache

def sh(binp, inp):
    return subprocess.run([binp], input=inp, capture_output=True, text=True).stdout

def sa_real(s):
    return [i+1 for i in sorted(range(len(s)), key=lambda i: s[i:])]

# complete brute force: over all CUT SETS of the rank order (2^(n-1)),
# build the string, verify its suffix array really is p
def brute_A(p):
    n = len(p)
    best = 10**9
    for mask in range(1 << (n-1)):
        # character = number of cuts before this rank
        ch = [0]*n
        cuts = 0
        for i in range(n):
            ch[i] = cuts
            if i < n-1 and (mask >> i) & 1: cuts += 1
        rk=[0]*n
        for i,x in enumerate(p): rk[x-1]=i
        s = "".join(chr(97+ch[rk[i]]) for i in range(n))
        if sa_real(s) == p:
            best = min(best, cuts+1)
    return best if best < 10**9 else -1

bad = 0
for n in range(1, 8):
    for p in itertools.permutations(range(1, n+1)):
        inp = f"{n}\n" + " ".join(map(str, p)) + "\n"
        got = int(sh("./A", inp).strip())
        exp = brute_A(list(p))
        if got != exp:
            print("A MISMATCH", n, p, got, exp); bad += 1
            if bad > 5: sys.exit(1)
    print("  n=%d done" % n)
print("A ok" if bad == 0 else "A FAILED")
