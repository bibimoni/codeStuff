import itertools, subprocess, random, sys

def sa_of(s):
    n = len(s)
    idx = sorted(range(n), key=lambda i: s[i:])
    return [i+1 for i in idx]

def min_distinct_brute(perm):
    n = len(perm)
    best = None
    for k in range(1, n+1):
        for tup in itertools.product(range(k), repeat=n):
            if sa_of(list(tup)) == list(perm):
                return k
    return -1

bad = 0
cases = []
for n in range(1, 7):
    for perm in itertools.permutations(range(1, n+1)):
        cases.append(list(perm))
# subsample n=6 to keep runtime sane? 720*6^6 ~ ok, python may be slowish. do all n<=5 fully, sample n=6
small = [c for c in cases if len(c) <= 5]
six = [c for c in cases if len(c) == 6]
random.seed(1)
sample6 = random.sample(six, 120)
tests = small + sample6

inp = []
for c in tests:
    inp.append(str(len(c)))
    inp.append(' '.join(map(str, c)))
inp = '\n'.join(inp) + '\n'
out = subprocess.run(['./Atest'], input=inp, capture_output=True, text=True)
got = out.stdout.split()
assert len(got) == len(tests), (len(got), len(tests), out.stderr)
for c, g in zip(tests, got):
    exp = min_distinct_brute(c)
    if int(g) != exp:
        bad += 1
        print('MISMATCH', c, 'got', g, 'exp', exp)
        if bad > 5: sys.exit(1)
print('A checked', len(tests), 'bad', bad)
