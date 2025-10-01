n, m = map(int, input().split())
grid = [input() for _ in range(n)]
cnt = [[[0, 0, 0, 0] for _ in range(m)] for _ in range(n)]
LEFT = 0
UP = 1
LEFT_DIAG = 2
RIGHT_DIAG = 3
found = False

for j in range(m):
	if grid[0][j] != '.':
		cnt[0][j][LEFT] = 1
		cnt[0][j][UP] = 1
		cnt[0][j][LEFT_DIAG] = 1
		cnt[0][j][RIGHT_DIAG] = 1

for i in range(n):
	for j in range(m):
		if grid[i][j] == '.':
			cnt[i][j][LEFT] = 0
			cnt[i][j][UP] = 0
			cnt[i][j][LEFT_DIAG] = 0
			cnt[i][j][RIGHT_DIAG] = 0
			continue

		if j - 1 >= 0 and grid[i][j - 1] == grid[i][j]:
			cnt[i][j][LEFT] = cnt[i][j - 1][LEFT] + 1
		else:
			cnt[i][j][LEFT] = 1
		
		if i - 1 >= 0 and grid[i - 1][j] == grid[i][j]:
			cnt[i][j][UP] = cnt[i - 1][j][UP] + 1
		else:
			cnt[i][j][UP] = 1
		
		if i - 1 >= 0 and j - 1 >= 0 and grid[i - 1][j - 1] == grid[i][j]:
			cnt[i][j][LEFT_DIAG] = cnt[i - 1][j - 1][LEFT_DIAG] + 1
		else:
			cnt[i][j][LEFT_DIAG] = 1
		
		if i - 1 >= 0 and j + 1 < m and grid[i - 1][j + 1] == grid[i][j]:
			cnt[i][j][RIGHT_DIAG] = cnt[i - 1][j + 1][RIGHT_DIAG] + 1
		else:
			cnt[i][j][RIGHT_DIAG] = 1

		if cnt[i][j][LEFT] >= 5 or cnt[i][j][UP] >= 5 or cnt[i][j][LEFT_DIAG] >= 5 or cnt[i][j][RIGHT_DIAG] >= 5:
			found = True
			break

	if found:
		break

if found:
	print("Yes")
else:
	print("No")