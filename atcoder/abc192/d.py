x = int(input())
m = int(input())


def f(x, n):
  s, p = 0, 1
  while x:
    d = x % 10
    x //= 10
    s += d * p
    p *= n
  return s


max_d = 0
xx = x
while xx:
  d = xx % 10
  xx //= 10
  max_d = max(max_d, d)

ans = 0
i = max_d + 1
while True:
  # print(x, i, f(x, i))
  if f(x, i) > m:
    break
  else:
    ans += 1
  i += 1

print(ans)
