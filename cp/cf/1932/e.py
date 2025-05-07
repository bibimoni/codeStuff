t = int(input());
for i in range(1, t + 1):
  n = int(input())
  num = input()
  ans = 0
  for i in range(1, n + 1):
    ans += int(num[:i])
  print(ans)