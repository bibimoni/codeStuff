import subprocess, sys, random
sys.path.insert(0, ".")
# reuse the validated direct+brute from expL by importing its functions
import importlib.util
spec = importlib.util.spec_from_file_location("expL", "expL.py")
src = open("expL.py").read()
src = src.split("R = random.Random")[0]  # drop the test driver
ns = {}
exec(src, ns)
brute = ns["brute"]; direct_islands = ns["direct_islands"]; direct_nook = ns["direct_nook"]
INF = ns["INF"]

# C++ solver compiled from L.cpp must match these on random event streams incl. updates
R = random.Random(int(sys.argv[1]) if len(sys.argv) > 1 else 0)

def gen_case():
    n = R.randint(2, 8)
    a = [0] + [R.randint(-5, 5) for _ in range(n)]
    b = [0] + [R.randint(-5, 5) for _ in range(n)]
    q = R.randint(1, 30)
    events = []
    for _ in range(q):
        typ = R.choice([1, 1, 1, 2, 3])
        if typ == 1:
            s = R.randint(1, n)
            if R.random() < 0.5 and s < n:
                t = R.randint(s + 1, n)
            else:
                t = n + 1
            events.append((1, s, t))
        elif typ == 2:
            events.append((2, R.randint(1, n), R.randint(-5, 5)))
        else:
            events.append((3, R.randint(1, n), R.randint(-5, 5)))
    return n, a, b, events

def run_cpp(n, a, b, events):
    inp = f"1\n{n} {len(events)}\n" + " ".join(map(str, a[1:])) + "\n" + " ".join(map(str, b[1:])) + "\n"
    for e in events:
        inp += " ".join(map(str, e)) + "\n"
    out = subprocess.run(["./L"], input=inp, capture_output=True, text=True)
    return [int(x) for x in out.stdout.split()]

def run_py(n, a, b, events):
    a = a[:]; b = b[:]
    res = []
    for e in events:
        if e[0] == 1:
            s, t = e[1], e[2]
            if t == n + 1:
                res.append(direct_nook(n, a, b, s))
            else:
                res.append(direct_islands(n, a, b, s, t))
        elif e[0] == 2:
            a[e[1]] = e[2]
        else:
            b[e[1]] = e[2]
    return res

bad = 0
for it in range(600):
    n, a, b, events = gen_case()
    got = run_cpp(n, a, b, events)
    exp = run_py(n, a, b, events)
    if got != exp:
        bad += 1
        if bad <= 3:
            print("STREAM MISMATCH n", n, "a", a[1:], "b", b[1:])
            print("events", events)
            for i, (g, e) in enumerate(zip(got, exp)):
                if g != e:
                    print("  first diff at query", i, "cpp", g, "py", e)
                    break
print("stream mismatches:", bad, "/600")
