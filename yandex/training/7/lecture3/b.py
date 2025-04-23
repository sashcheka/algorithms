n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]
nums = [0] * n

for i in range(n):
	for j in range(n):
		if i == j:
			continue

		nums[i] |= matrix[i][j]
		nums[j] |= matrix[i][j]

print(*nums)