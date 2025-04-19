def query(tree, idx, tl, tr, l, r):
	if l > r:
		return [0, 0]

	if l == tl and r == tr:
		return tree[idx]

	tm = tl + (tr - tl) // 2
	left = query(tree, 2 * idx + 1, tl, tm, l, min(r, tm))
	right = query(tree, 2 * idx + 2, tm + 1, tr, max(l, tm + 1), r)

	if left[0] == right[0]:
		return [left[0], left[1] + right[1]]
	elif left[0] > right[0]:
		return left
	else:
		return right


def build(tree, size, nums):
	for i in range(len(nums)):
		tree[size - 1 + i] = [nums[i], 1]

	for i in range(size - 2, -1, -1):
		left = tree[2 * i + 1]
		right = tree[2 * i + 2]

		if left[0] == right[0]:
			tree[i] = [left[0], left[1] + right[1]]
		elif left[0] > right[0]:
			tree[i] = left
		else:
			tree[i] = right


def main():
	n = int(input())
	nums = list(map(int, input().split()))

	p = 0
	while 1 << p < n:
		p += 1
	size = 1 << p
	tree = [[0, 0] for _ in range(2 * size - 1)]

	build(tree, size, nums)

	k = int(input())
	for i in range(k):
		l, r = map(int, input().split())
		max_value, count = query(tree, 0, 0, size - 1, l - 1, r - 1) # tree, root_idx, tl, tr, l, r
		print(max_value, count)


if __name__ == "__main__":
	main()