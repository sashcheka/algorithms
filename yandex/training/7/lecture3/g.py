def update(fenwick, i, diff):
	n = len(fenwick)
	while i < n:
		fenwick[i] += diff
		i = i | (i + 1)
	return


def query(fenwick, i):
	prefix_sum = 0
	while i >= 0:
		prefix_sum += fenwick[i]
		i = (i & (i + 1)) - 1
	return prefix_sum


def main():
	n, k = map(int, input().split())
	fenwick = [0] * n
	nums = [0] * n

	for i in range(k):
		line = list(input().split())

		if line[0] == "A":
			i = int(line[1]) - 1
			x = int(line[2])
			diff = x - nums[i]
			nums[i] = x
			update(fenwick, i, diff)
		elif line[0] == "Q":
			l = int(line[1]) - 1
			r = int(line[2]) - 1
			range_sum = query(fenwick, r) - query(fenwick, l - 1)
			print(range_sum)

	return


if __name__ == "__main__":
	main()