def isp(num):
    num_str = str(num)
    return num_str == num_str[::-1]


def rev(num):
    num_str = str(num)
    return int(num_str[::-1])


num = int(input())
n, m = list(map(int, input().split()))
# n = min(n, 500)
ans = 0
can = False
while n > 0:
    n -= 1
    if len(str(num)) > m:
        break
    if isp(num):
        can = True
        break
    ans += 1
    num = num + rev(num)

print("YES" if not can else "NO")
print(ans)
print(num)
