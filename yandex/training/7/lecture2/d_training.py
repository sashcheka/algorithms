def update(tree, idx, v):
	while idx > 0:
		idx = (idx - 1) // 2
		left = tree[2 * idx + 1]
		right = tree[2 * idx + 2]
		tree[idx] = max(left, right)


def query(tree, idx, tl, tr, l, r):
	if l > r:
		return -1

	if l == tl and r == tr:
		return tree[idx]

	tm = tl + (tr - tl) // 2
	left = query(tree, 2 * idx + 1, tl, tm, l, r)
	right = query(tree, 2 * idx + 2, tm + 1, tr, l, r)

	return max(left, right)


def build(tree, size, nums):
	for i in range(len(nums)):
		tree[size - 1 + i] = nums[i]

	for i in range(size - 2, -1, -1):
		left = tree[2 * i + 1]
		right = tree[2 * i + 2]
		tree[i] = max(left, right)


def main():
	n = int(input())
	nums = list(map(int, input().split()))

	p = 0
	while 1 << p < n:
		p += 1
	size = 1 << p
	tree = [-1] * (2 * size - 1)

	build(tree, size, nums)

	k = int(input())
	for i in range(k):
		oper, l, r = list(input().split())
		if oper == 's':
			max_value = query(tree, 0, 0, size - 1, int(l) - 1, int(r) - 1) # tree, root_idx, tl, tr, l, r
			print(max_value)
		else:
			idx, v = int(l), int(r)
			tree[size - 1 + idx - 1] = v
			update(tree, size - 1 + idx - 1, v)


if __name__ == "__main__":
	main()