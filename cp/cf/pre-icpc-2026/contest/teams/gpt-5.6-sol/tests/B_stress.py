import itertools
import subprocess

n = 8
edges = [(0, 1), (1, 2), (2, 0), (2, 3), (4, 5), (5, 6)]
states = list(itertools.product(range(2), repeat=n))
data = [f"{n} {len(edges)} {len(states)}"]
data += [f"{u+1} {v+1}" for u, v in edges]
data += ["".join(map(str, s)) for s in states]
p = subprocess.run(["/tmp/gpt-sol-B"], input="\n".join(data) + "\n", text=True, capture_output=True, check=True)
lines = p.stdout.splitlines()
assert len(lines) == len(states)
for state, line in zip(states, lines):
    possible = False
    for mask in range(1 << n):
        cur = list(state)
        for u in range(n):
            if mask >> u & 1:
                cur[u] ^= 1
                for a, b in edges:
                    if a == u: cur[b] ^= 1
                    if b == u: cur[a] ^= 1
        if all(cur):
            possible = True
            break
    if line == "-1":
        assert not possible, state
        continue
    out = list(map(int, line.split()))
    assert out[0] == len(out) - 1 and possible
    cur = list(state)
    for u in out[1:]:
        u -= 1
        cur[u] ^= 1
        for a, b in edges:
            if a == u: cur[b] ^= 1
            if b == u: cur[a] ^= 1
    assert all(cur), (state, line)
print("B stress OK")
