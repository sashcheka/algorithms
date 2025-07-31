n, k = map(int, input().split())
a = list(map(int, input().split()))
MIN = float("-inf")
dp = [[MIN] * (k+1) for _ in range(n+1)]
dp[0][0] = 0

for t in range(k+1):
    if t > 0:
        best_pref = dp[0][t-1]
        for i in range(1, n):
            if dp[i][t-1] > best_pref:
                best_pref = dp[i][t-1]
            dp[i][t] = max(dp[i][t], best_pref)

    for i in range(1, n+1):
        if dp[i-1][t] != MIN:
            dp[i][t] = max(dp[i][t], dp[i-1][t] + a[i-1])
        if i >= 2 and dp[i-2][t] != MIN:
            dp[i][t] = max(dp[i][t], dp[i-2][t] + a[i-1])

print(max(dp[n]))