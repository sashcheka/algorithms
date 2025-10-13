import sys
sys.setrecursionlimit(1_000_000)

n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
memo = [[-1] * m for _ in range(n)]

def dfs(r, c):
	if memo[r][c] != -1: return memo[r][c]
	cand = 1
	for dr, dc in dirs:
		nr = r + dr
		nc = c + dc
		if nr < 0 or nr >= n or nc < 0 or nc >= m or grid[r][c] + 1 != grid[nr][nc]:
			continue
		cand = max(cand, dfs(nr, nc) + 1)
	memo[r][c] = cand
	return memo[r][c]

ans = 1
for i in range(n):
	for j in range(m):
		ans = max(ans, dfs(i, j))
print(ans)