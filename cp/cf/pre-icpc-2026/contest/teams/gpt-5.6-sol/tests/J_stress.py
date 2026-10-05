import itertools
import random
import subprocess

cases = []
random.seed(1)
for n in range(1, 9):
    for _ in range(150):
        cases.append(tuple(random.randint(-3, 3) for _ in range(n)))
data = [str(len(cases))]
expected = []
for a in cases:
    data += [str(len(a)), " ".join(map(str, a))]
    count = 0
    for cuts in range(1 << (len(a) - 1)):
        sums, start = [], 0
        for i in range(len(a) - 1):
            if cuts >> i & 1:
                sums.append(sum(a[start:i+1]))
                start = i + 1
        sums.append(sum(a[start:]))
        count += len(set(sums)) == 1
    expected.append(count % 1000000007)
p = subprocess.run(["/tmp/gpt-sol-J"], input="\n".join(data) + "\n", text=True, capture_output=True, check=True)
got = list(map(int, p.stdout.split()))
assert got == expected, next((c, x, y) for c, x, y in zip(cases, got, expected) if x != y)
print("J stress OK")
