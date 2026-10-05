import random, sys
random.seed(int(sys.argv[1]))
n = random.randint(1, 7)
print(n)
for v in range(2, n+1):
    u = random.randint(1, v-1)
    w = random.choice([0,1,2])
    print(u, v, w)
