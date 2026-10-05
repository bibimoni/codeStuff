import itertools
import random
import subprocess

MOD = 998244353
random.seed(2)
for n in range(1, 9):
    for _ in range(40):
        edges = []
        for v in range(1, n):
            u = random.randrange(v)
            w = random.randrange(3)
            edges.append((u, v, w))
        expected = 0
        for p in itertools.permutations(range(n)):
            pos = [0] * n
            for i, v in enumerate(p): pos[v] = i
            ok = True
            for u, v, w in edges:
                if w == 1 and not pos[u] < pos[v]: ok = False
                if w == 2 and not pos[v] < pos[u]: ok = False
            expected += ok
        data = [str(n)] + [f"{u+1} {v+1} {w}" for u, v, w in edges]
        got = subprocess.run(["/tmp/gpt-sol-E"], input="\n".join(data) + "\n", text=True, capture_output=True, check=True)
        assert int(got.stdout) == expected % MOD, (n, edges, got.stdout, expected)
print("E stress OK")
