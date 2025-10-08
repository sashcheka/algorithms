n = int(input())
grid = [input() for _ in range(n)]
dp = [[-1, -1, -1] for _ in range(n)]
best = 0
if grid[0] == "WWW":
	print(0)
else:
	for i in range(3):
		if grid[0][i] == 'W': continue
		dp[0][i] = 1 if grid[0][i] == 'C' else 0
		best = max(best, dp[0][i])
	for i in range(1, n):
		for j in range(3):
			if grid[i][j] == 'W': continue
			for dj in [-1, 0, 1]:
				pj = j + dj
				if pj < 0 or pj >= 3 or dp[i - 1][pj] == -1: continue
				coin = 1 if grid[i][j] == 'C' else 0
				dp[i][j] = max(dp[i][j], dp[i - 1][pj] + coin)
			best = max(best, dp[i][j])
	print(best)