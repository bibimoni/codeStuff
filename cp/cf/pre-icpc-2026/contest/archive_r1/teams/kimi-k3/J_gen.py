import random, sys
seed = int(sys.argv[1])
random.seed(seed)
t = random.randint(1, 20)
print(t)
for _ in range(t):
    n = random.randint(1, 12)
    print(n)
    print(' '.join(str(random.randint(-5, 5)) for _ in range(n)))
