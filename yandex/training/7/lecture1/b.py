def main():
	t = int(input())

	for _ in range(t):
		n = int(input())
		a = list(map(int, input().split()))

		cuts = []
		i = 0
		max_pos_len = float("inf")
		curr_len = 0
		while i < n:
			max_pos_len = min(max_pos_len, a[i])
			curr_len += 1

			if max_pos_len == curr_len:
				max_pos_len = float("inf")
				cuts.append(curr_len)
				curr_len = 0
			elif max_pos_len > curr_len:
				pass
			elif max_pos_len < curr_len:
				max_pos_len = a[i]
				cuts.append(curr_len - 1)
				curr_len = 1

			if i == n - 1 and curr_len > 0:
				cuts.append(curr_len)
			i += 1

		print(len(cuts))
		print(*cuts)

	return


if __name__ == "__main__":
	main()