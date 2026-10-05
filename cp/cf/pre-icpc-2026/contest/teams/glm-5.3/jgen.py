import random
t=random.randint(1,15)
lines=[str(t)]
for _ in range(t):
    n=random.randint(1,8)
    lines.append(str(n))
    lines.append(' '.join(str(random.randint(-5,5)) for _ in range(n)))
print('\n'.join(lines))
