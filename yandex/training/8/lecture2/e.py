from collections import deque

n, k = map(int, input().split())
a = list(map(int, input().split()))

m = n - k + 1
sum_k = [0] * m
s = 0
for i in range(n):
    s += a[i]
    if i >= k:
        s -= a[i - k]
    if i >= k - 1:
        sum_k[i - k + 1] = s

min_k = [0] * m
dq = deque()
for i in range(n):
    while dq and dq[0] <= i - k:
        dq.popleft()
    while dq and a[dq[-1]] >= a[i]:
        dq.pop()
    dq.append(i)
    if i >= k - 1:
        min_k[i - k + 1] = a[dq[0]]

ww = [sum_k[i] * min_k[i] for i in range(m)] # win win WW

dp = [0] * (n + 1)
i = m - 1
while i >= 0:
    take = ww[i] + dp[i + k]
    skip = dp[i + 1]
    dp[i] = max(take, skip)
    i -= 1

ans = []
i = 0
while i < m:
    take = ww[i] + dp[i + k]
    skip = dp[i + 1]
    if take >= skip:
        ans.append(i + 1)
        i += k
    else:
        i += 1

print(len(ans))
if ans:
    print(*ans)