def main():
	n, m = map(int, input().split())

	x = list(map(int, input().split()))
	y = list(map(int, input().split()))

	for i in range(n):
		x[i] = (x[i] + 1, i + 1)
	for i in range(m):
		y[i] = (y[i], i + 1)

	x.sort(reverse=True)
	y.sort(reverse=True)

	result = [0] * n
	success = 0
	i = 0
	j = 0
	while i < n and i < m:
		if y[j][0] >= x[i][0]:
			result[x[i][1] - 1] = y[j][1]
			success += 1
			i += 1
			j += 1
		elif y[j][0] < x[i][0]:
			result[x[i][1] - 1] = 0
			i += 1

	if i < n:
		result[x[i][1] - 1] = 0
		success += 1
		i += 1	

	print(success)
	print(*result)
	return


if __name__ == "__main__":
	main()