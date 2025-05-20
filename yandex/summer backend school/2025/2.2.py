n = int(input())
prices = [int(input()) for _ in range(n)]
MAX = 200
dupa = [0] * (MAX + 1)
ans = 0
for price in prices:
    for i in range(price): ans += dupa[i]
    dupa[price] += 1
print(ans)