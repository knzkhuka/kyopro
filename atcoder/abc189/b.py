from decimal import *
n, x = map(int, input().split())
x = Decimal(x)
ans = -1
hund = Decimal(100)
acc = Decimal(0)
for i in range(n):
  v, p = map(Decimal, input().split())
  acc += v*p/hund
  if acc > x and ans==-1:
    ans = i+1
print(ans)
