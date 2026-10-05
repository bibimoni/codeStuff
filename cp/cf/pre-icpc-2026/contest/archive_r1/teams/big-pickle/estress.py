import random, subprocess, sys, os
os.chdir('/Users/distiled/codeStuff/cp/cf/pre-icpc-2026/contest/teams/big-pickle')
random.seed(int(sys.argv[1]) if len(sys.argv) > 1 else 3)
NMAX = int(sys.argv[2]) if len(sys.argv) > 2 else 6
NC = int(sys.argv[3]) if len(sys.argv) > 3 else 60
bad = 0
for it in range(NC * NMAX):
    n = random.randint(1, NMAX)
    edges = []
    for v in range(1, n):
        u = random.randrange(v)
        edges.append((u + 1, v + 1, random.choice([0, 0, 1, 2])))
    random.shuffle(edges)
    inp = f"{n}\n" + "".join(f"{u} {v} {w}\n" for u, v, w in edges)
    open('/tmp/case.txt', 'w').write(inp)
    a = subprocess.run(['./e'], stdin=open('/tmp/case.txt'), capture_output=True, text=True).stdout.strip()
    b = subprocess.run(['./eb'], stdin=open('/tmp/case.txt'), capture_output=True, text=True).stdout.strip()
    if a != b:
        bad += 1
        print("MISMATCH got", a, "want", b)
        print(inp)
        if bad > 2: break
print("done, mismatches:", bad)
