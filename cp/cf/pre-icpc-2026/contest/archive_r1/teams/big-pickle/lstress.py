import random, subprocess, sys, os
os.chdir('/Users/distiled/codeStuff/cp/cf/pre-icpc-2026/contest/teams/big-pickle')
random.seed(int(sys.argv[1]) if len(sys.argv) > 1 else 1)
NMAX = int(sys.argv[2]) if len(sys.argv) > 2 else 6
NC = int(sys.argv[3]) if len(sys.argv) > 3 else 60
W = int(sys.argv[4]) if len(sys.argv) > 4 else 3
bad = 0
for it in range(NC):
    cases = []
    for _ in range(random.randint(1, 3)):
        n = random.randint(2, NMAX)
        a = [random.randint(-W, W) for _ in range(n)]
        b = [random.randint(-W, W) for _ in range(n)]
        q = random.randint(1, 25)
        ev = []
        for _ in range(q):
            r = random.random()
            if r < 0.5:
                s = random.randint(1, n)
                t = random.randint(s + 1, n + 1)
                ev.append(f"1 {s} {t}")
            elif r < 0.75:
                ev.append(f"2 {random.randint(1, n)} {random.randint(-W, W)}")
            else:
                ev.append(f"3 {random.randint(1, n)} {random.randint(-W, W)}")
        cases.append((n, a, b, ev))
    inp = f"{len(cases)}\n" + "".join(
        f"{n} {len(ev)}\n{' '.join(map(str, a))}\n{' '.join(map(str, b))}\n" + "\n".join(ev) + "\n"
        for n, a, b, ev in cases)
    open('/tmp/lcase.txt', 'w').write(inp)
    x = subprocess.run(['./l'], stdin=open('/tmp/lcase.txt'), capture_output=True, text=True).stdout.split()
    y = subprocess.run(['./lb'], stdin=open('/tmp/lcase.txt'), capture_output=True, text=True).stdout.split()
    if x != y:
        bad += 1
        print("MISMATCH")
        print(inp)
        print("got ", x)
        print("want", y)
        if bad > 2:
            break
print("done, mismatches:", bad)
