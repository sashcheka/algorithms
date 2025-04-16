import math


def main():
	n = int(input())
	nums = list(map(int, input().split()))

	_pow = int(math.log2(n)) + 1
	sparce_table = [[[0, 0] for _ in range(n)] for _ in range(_pow)] # max_value, count
	
	for i in range(n):
		sparce_table[0][i] = [nums[i], 1]

	for i in range(1, _pow):
		offset = 1 << (i - 1)
		for j in range(n - (1 << i) + 1):
			first = sparce_table[i - 1][j]
			second = sparce_table[i - 1][j + offset]
			if first[0] == second[0]:
				sparce_table[i][j] = [first[0], first[1] + second[1]]
			elif first[0] < second[0]:
				sparce_table[i][j] = [second[0], second[1]]
			elif first[0] > second[0]:
				sparce_table[i][j] =[first[0],  first[1]]
	for row in sparce_table:
		print(*row)

	pows = [0] * (n + 1)	
	j = 0
	for i in range(1, n + 1):
		pows[i] = int(math.log2(i))
	# print(*pows)

	k = int(input())
	for _ in range(k):
		l, r = map(int, input().split())
		l -= 1
		r -= 1

		d = r - l + 1
		j = pows[d]
		# print(f"d: {d}, j: {j}")

		first = sparce_table[j][l]
		second = sparce_table[j][r - (1 << j) + 1]

		if l == r - (1 << j) + 1:
			print(first[0], first[1])
		else:
			if first[0] == second[0]:
				print(first[0], first[1] + second[1])
			elif first[0] < second[0]:
				print(second[0], second[1])
			elif first[0] > second[0]:
				print(first[0], first[1])


if __name__ == "__main__":
	main()