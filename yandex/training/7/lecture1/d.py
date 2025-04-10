def main():
	n, m = map(int, input().split())
	gs = list(map(int, input().split()))

	dp = [False] * (m + 1)
	dp[0] = True

	for g in gs:
		for cand in range(m, g - 1, -1):
			dp[cand] = dp[cand] or dp[cand - g]

	for i in range(m, -1, -1):
		if dp[i]:
			print(i)
			return

	return


if __name__ == "__main__":
	main()