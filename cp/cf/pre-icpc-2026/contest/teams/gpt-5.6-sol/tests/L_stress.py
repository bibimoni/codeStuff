import random
import subprocess

random.seed(3)
n = 8
a = [random.randint(-5, 5) for _ in range(n)]
b = [random.randint(-5, 5) for _ in range(n)]
initial_a, initial_b = a[:], b[:]
events, expected = [], []

def shortest(s, t):
    graph = [[] for _ in range(n + 1)]
    for i, w in enumerate(a):
        j = (i + 1) % n
        graph[i].append((j, w)); graph[j].append((i, w))
    for i, w in enumerate(b):
        graph[i].append((n, w)); graph[n].append((i, w))
    best = 10**18
    def dfs(v, seen, cost):
        nonlocal best
        if v == t:
            best = min(best, cost)
            return
        for u, w in graph[v]:
            if not (seen >> u & 1): dfs(u, seen | 1 << u, cost + w)
    dfs(s, 1 << s, 0)
    return best

for _ in range(250):
    typ = random.choices([1, 2, 3], [6, 2, 2])[0]
    if typ == 1:
        s, t = sorted(random.sample(range(n + 1), 2))
        events.append((1, s + 1, t + 1))
        expected.append(shortest(s, t))
    elif typ == 2:
        x, w = random.randrange(n), random.randint(-5, 5)
        a[x] = w
        events.append((2, x + 1, w))
    else:
        x, w = random.randrange(n), random.randint(-5, 5)
        b[x] = w
        events.append((3, x + 1, w))

data = ["1", f"{n} {len(events)}", " ".join(map(str, initial_a)), " ".join(map(str, initial_b))]
data += [" ".join(map(str, e)) for e in events]
p = subprocess.run(["/tmp/gpt-sol-L"], input="\n".join(data) + "\n", text=True, capture_output=True, check=True)
got = list(map(int, p.stdout.split()))
assert got == expected, next((i, x, y) for i, (x, y) in enumerate(zip(got, expected)) if x != y)
print("L stress OK")
