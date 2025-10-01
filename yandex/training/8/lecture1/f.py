n, m = map(int, input().split())
grid = [input() for _ in range(n)]
row = [[0, 0] for _ in range(n)]
col = [[0, 0] for _ in range(m)]
VAL = 0
QUEST = 1
for i in range(n):
	for j in range(m):
		if grid[i][j] == '+':
			row[i][VAL] += 1
			col[j][VAL] += 1
		elif grid[i][j] == '-':
			row[i][VAL] -= 1
			col[j][VAL] -= 1
		elif grid[i][j] == '?':
			row[i][QUEST] += 1
			col[j][QUEST] += 1
best = float("-inf")
for i in range(n):
	for j in range(m):
		cand = row[i][VAL] - col[j][VAL]
		cand += row[i][QUEST] + col[j][QUEST]
		if grid[i][j] == '?':
			cand -= 2
		best = max(best, cand)
print(best)