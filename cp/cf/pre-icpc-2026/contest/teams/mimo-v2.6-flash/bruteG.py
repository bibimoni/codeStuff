import random, subprocess

DIRS = [(0,1), (-1,0), (0,-1), (1,0)]

def segments(d):
    x = y = 0
    segs = []
    for i, dist in enumerate(d):
        dx, dy = DIRS[i % 4]
        nx, ny = x + dx*dist, y + dy*dist
        segs.append(((x,y),(nx,ny)))
        x, y = nx, ny
    return segs

def inter(s1, s2):
    (ax, ay), (bx, by) = s1
    (cx, cy), (dx2, dy2) = s2
    h1 = ay == by; v1 = ax == bx
    h2 = cy == dy2; v2 = cx == dx2
    if h1 and v2:
        return min(ax,bx) <= cx <= max(ax,bx) and min(cy,dy2) <= ay <= max(cy,dy2)
    if v1 and h2:
        return min(cx,dx2) <= ax <= max(cx,dx2) and min(ay,by) <= cy <= max(ay,by)
    if h1 and h2:
        if ay != cy: return False
        return max(min(ax,bx), min(cx,dx2)) <= min(max(ax,bx), max(cx,dx2))
    if v1 and v2:
        if ax != cx: return False
        return max(min(ay,by), min(cy,dy2)) <= min(max(ay,by), max(cy,dy2))
    return False

def bruteG(d):
    segs = segments(d)
    n = len(segs)
    for i in range(n):
        for j in range(n):
            if abs(i-j) <= 1: continue
            if inter(segs[i], segs[j]): return "Yes"
    return "No"

random.seed(7)
cases = []
expected = []
# samples
cases.append([2,1,1,2]); expected.append("Yes")
cases.append([1,2,3,4]); expected.append("No")
cases.append([1,1,1,1,1]); expected.append("Yes")
while len(cases) < 300:
    n = random.randint(1, 14)
    d = [random.randint(1, 6) for _ in range(n)]
    cases.append(d)
# a few bigger spiral-y
for _ in range(50):
    n = random.randint(15, 40)
    d = [random.randint(1, 10) for _ in range(n)]
    cases.append(d)

for d in cases:
    if len(d) <= 14:
        expected.append(bruteG(d))

lines = [str(len(cases))]
for d in cases:
    lines.append(str(len(d)))
    lines.append(" ".join(map(str, d)))
inp = "\n".join(lines) + "\n"
res = subprocess.run(['./Gtest'], input=inp, capture_output=True, text=True).stdout.splitlines()
bad = 0
# only first 300 have expected (len<=14 ones) — recompute mask
idx = 0
for d, got in zip(cases, res):
    if len(d) <= 14:
        exp = bruteG(d)
        if exp != got:
            bad += 1
            print("G MISMATCH", d, "exp", exp, "got", got)
    idx += 1
print("G checked", sum(1 for d in cases if len(d) <= 14), "bad", bad, "lines", len(res), len(cases))
