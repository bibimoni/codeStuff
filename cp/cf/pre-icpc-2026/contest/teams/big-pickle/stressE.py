import random, subprocess, sys

R = random.Random(int(sys.argv[1]) if len(sys.argv) > 1 else 0)

def run(n, edges):
    inp = f"{n}\n" + "".join(f"{u+1} {v+1} {w}\n" for u, v, w in edges)
    out = subprocess.run(["./E"], input=inp, capture_output=True, text=True)
    return int(out.stdout.strip())

def brute(n, edges):
    import itertools
    cons = []
    for u, v, w in edges:
        if w == 1: cons.append((u, v))
        elif w == 2: cons.append((v, u))
    cnt = 0
    for p in itertools.permutations(range(n)):
        pos = {x: i for i, x in enumerate(p)}
        if all(pos[a] < pos[b] for a, b in cons): cnt += 1
    return cnt

def rand_tree(n):
    edges = []
    for v in range(1, n):
        p = R.randrange(v)
        edges.append((p, v, R.choice([0, 1, 2])))
    return edges

bad = 0
# random small vs brute
for it in range(1500):
    n = R.randint(1, 8)
    e = rand_tree(n)
    b, c = brute(n, e), run(n, e)
    if b != c:
        bad += 1
        if bad <= 5: print("MISMATCH", n, e, "brute", b, "cpp", c)
print("small-vs-brute mismatches:", bad, "/1500")

# larger random self-consistency vs expE2 python DP
import importlib.util
spec = importlib.util.spec_from_file_location("expE2", "expE2.py")
# expE2 runs tests on import; instead re-implement call by exec of functions only
src = open("expE2.py").read().split("R = random.Random")[0]
ns = {}
exec(src, ns)
solve_E = ns["solve_E"]
bad2 = 0
for it in range(300):
    n = R.randint(1, 60)
    e = rand_tree(n)
    p = solve_E(n, e)
    c = run(n, e)
    if p != c:
        bad2 += 1
        if bad2 <= 3: print("BIG MISMATCH n", n, "py", p, "cpp", c)
print("mid-vs-py mismatches:", bad2, "/300")

# edge: n=1
print("n=1:", run(1, []), "(expect 1)")
# all free path n=6 => 720
e = [(i, i+1, 0) for i in range(5)]
print("all-free n=6 path:", run(6, e), "(expect 720)")
# all-free star n=6 => 720
e = [(0, i, 0) for i in range(1, 6)]
print("all-free n=6 star:", run(6, e), "(expect 720)")
# all w=1 chain => 1
e = [(i, i+1, 1) for i in range(5)]
print("all-w1 chain n=6:", run(6, e), "(expect 1)")
# all w=2 chain reversed => 1
e = [(i, i+1, 2) for i in range(5)]
print("all-w2 chain n=6:", run(6, e), "(expect 1)")
# star with center last: 0->i all w=1 => 5! = 120
e = [(0, i, 1) for i in range(1, 6)]
print("star 0->all w=1:", run(6, e), "(expect 120)")
# star with center first: i->0 all w=1 => 5! = 120
e = [(i, 0, 1) for i in range(1, 6)]
print("star all->0 w=1:", run(6, e), "(expect 120)")
# two predecessors one node, rest free n=3 edges (0,1,1),(0,2,1): 2 before? 0->1,0->2 => 0 first, 2 orders
e = [(0, 1, 1), (0, 2, 1)]
print("0->1,0->2:", run(3, e), "(expect 2)")
# w=0 edge only n=2 => 2
e = [(0, 1, 0)]
print("single w=0 edge:", run(2, e), "(expect 2)")
