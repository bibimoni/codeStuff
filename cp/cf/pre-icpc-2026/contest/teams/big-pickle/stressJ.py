import random, subprocess, sys, itertools

R = random.Random(int(sys.argv[1]) if len(sys.argv) > 1 else 0)
MOD = 10**9 + 7

def run(cases):
    inp = f"{len(cases)}\n" + "".join(
        f"{len(a)}\n" + " ".join(map(str, a)) + "\n" for a in cases)
    out = subprocess.run(["./J"], input=inp, capture_output=True, text=True)
    return [int(x) for x in out.stdout.split()]

def brute(a):
    n = len(a)
    total = 0
    for mask in range(1 << (n - 1)):
        cuts = [i + 1 for i in range(n - 1) if mask >> i & 1]  # cut after position i+1
        bounds = [0] + cuts + [n]
        sums = []
        ok = True
        for x in range(len(bounds) - 1):
            s = sum(a[bounds[x]:bounds[x + 1]])
            sums.append(s)
        if len(set(sums)) == 1:
            total += 1
    return total % MOD

bad = 0
batch = []
expected = []
for it in range(3000):
    n = R.randint(1, 11)
    a = [R.randint(-4, 4) for _ in range(n)]
    batch.append(a)
    expected.append(brute(a))
    if len(batch) == 100:
        got = run(batch)
        for i, (g, e) in enumerate(zip(got, expected)):
            if g != e:
                bad += 1
                if bad <= 5: print("MISMATCH", batch[i], "brute", e, "cpp", g)
        batch, expected = [], []
if batch:
    got = run(batch)
    for i, (g, e) in enumerate(zip(got, expected)):
        if g != e:
            bad += 1
            if bad <= 5: print("MISMATCH", batch[i], "brute", e, "cpp", g)
print("mismatches:", bad, "/3000")
