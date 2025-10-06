n = int(input())
dp = [0] * (n + 1)
dp[0] = 1
for i in range(n + 1):
	if i + 1 < n + 1:
		dp[i + 1] += dp[i]
	if i + 2 < n + 1:
		dp[i + 2] += dp[i]
	if i + 3 < n + 1:
		dp[i + 3] += dp[i]
print(dp[n])