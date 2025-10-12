from queue import PriorityQueue

n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
dp = [[-1] * m for _ in range(n)]

ans = 1
pq = PriorityQueue()
for i in range(n):
	for j in range(m):
		if dp[i][j] != -1: continue
		pq.put([1, i, j])  # length, row, col
		while not pq.empty():
			l, r, c = pq.get()
			if dp[r][c] >= l: continue
			dp[r][c] = l
			ans = max(ans, l)
			for dr, dc in dirs:
				nr = r + dr
				nc = c + dc
				if nr < 0 or nr >= n or nc < 0 or nc >= m: continue
				if grid[nr][nc] + 1 != grid[r][c]: continue
				if dp[nr][nc] >= l + 1: continue
				pq.put([l + 1, nr, nc])

print(ans)