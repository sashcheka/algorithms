def main():
	m = int(input())
	a = list(map(int, input().split()))

	for i in range(1, len(a)):
		a[i] = max(a[i], 2 * a[i - 1])

	print(*a)

	result = float("inf")
	cost = 0

	for i in range(len(a) - 1, -1, -1):
		count = m // a[i]
		m = m % a[i]
		cost += count * (1 << i)
		if m == 0:
			result = min(result, cost)
		else:
			result = min(result, cost + (1 << i))

	print(result)
	return


if __name__ == "__main__":
	main()