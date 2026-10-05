import random, sys
random.seed(int(sys.argv[1]))
tc = random.randint(1, 3)
print(tc)
for _ in range(tc):
    n = random.randint(2, 7)
    q = random.randint(1, 20)
    print(n, q)
    print(' '.join(str(random.randint(-5, 5)) for _ in range(n)))
    print(' '.join(str(random.randint(-5, 5)) for _ in range(n)))
    for _ in range(q):
        ty = random.randint(1, 3)
        if ty == 1:
            s = random.randint(1, n+1)
            t = random.randint(1, n+1)
            if s == t:
                t = s % (n+1) + 1
            if s > t: s, t = t, s
            print(1, s, t)
        elif ty == 2:
            print(2, random.randint(1, n), random.randint(-5, 5))
        else:
            print(3, random.randint(1, n), random.randint(-5, 5))
