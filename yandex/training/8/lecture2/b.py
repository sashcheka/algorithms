s = input()
n = len(s)
L = 0
R = 1
dp = [[0, 0] for _ in range(n + 1)]
dp[0][L] = 0
dp[0][R] = 1
for i in range(n):
	if s[i] == 'L':
		dp[i + 1][R] = dp[i][R]
		dp[i + 1][L] = min(dp[i][L] + 1, dp[i + 1][R] + 1)
	elif s[i] == 'R':
		dp[i + 1][L] = dp[i][L]
		dp[i + 1][R] = min(dp[i][R] + 1, dp[i + 1][L] + 1)
	elif s[i] == 'B':
		dp[i + 1][L] = dp[i][L] + 1
		dp[i + 1][R] = dp[i][R] + 1
print(dp[n][R])