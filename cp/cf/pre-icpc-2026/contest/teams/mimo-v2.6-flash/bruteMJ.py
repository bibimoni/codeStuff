import itertools, random, subprocess, sys

def inv_count(p):
    return sum(1 for i in range(len(p)) for j in range(i+1, len(p)) if p[i] > p[j])

def bruteM(n, m, k):
    ps = [p for p in itertools.permutations(range(1, n+1)) if inv_count(p) == m]
    ps.sort()
    if k > len(ps): return "-1"
    return " ".join(map(str, ps[k-1]))

def bruteJ(arr):
    n = len(arr)
    cnt = 0
    for mask in range(1 << (n-1)):
        cuts = [0] + [i+1 for i in range(n-1) if mask >> i & 1] + [n]
        sums = [sum(arr[cuts[i]:cuts[i+1]]) for i in range(len(cuts)-1)]
        if len(set(sums)) == 1: cnt += 1
    return cnt % (10**9+7)

random.seed(42)
# --- M ---
lines = []
cases = []
for _ in range(60):
    n = random.randint(1, 7)
    m = random.randint(0, n*(n-1)//2)
    k = random.randint(1, 40)
    cases.append((n, m, k))
lines.append(str(len(cases)))
for n, m, k in cases: lines.append(f"{n} {m} {k}")
inp = "\n".join(lines) + "\n"
open('/tmp/min.txt', 'w').write(inp)
res = subprocess.run(['./Mtest'], input=inp, capture_output=True, text=True).stdout.splitlines()
bad = 0
for (n, m, k), got in zip(cases, res):
    exp = bruteM(n, m, k)
    if exp != got:
        bad += 1
        print("M MISMATCH", n, m, k, "exp", exp, "got", got)
print("M checked", len(cases), "bad", bad)

# --- J ---
lines = []
arrs = []
for _ in range(80):
    n = random.randint(1, 9)
    arr = [random.randint(-5, 5) for _ in range(n)]
    arrs.append(arr)
    lines.append(str(n))
    lines.append(" ".join(map(str, arr)))
inp = str(len(arrs)) + "\n" + "\n".join(lines) + "\n"
open('/tmp/jin.txt', 'w').write(inp)
res = subprocess.run(['./Jtest'], input=inp, capture_output=True, text=True).stdout.splitlines()
bad = 0
for arr, got in zip(arrs, res):
    exp = str(bruteJ(arr))
    if exp != got:
        bad += 1
        print("J MISMATCH", arr, "exp", exp, "got", got)
print("J checked", len(arrs), "bad", bad)
