a, b, m = [int(x) for x in input().split()]
a -= 1;
s1 = b * (b + 1) * (2 * b + 1) // 6;
s2 = a * (a + 1) * (2 * a + 1) // 6;
print((s1 - s2) % m)
