def is_valid(n, a, b, k):
	prefix_sum_a = 0
	run_prefix_sum_b = 0
	r = 0
	for i in range(n):
		prefix_sum_a += a[i]
		m = min(i + k + 1, n)
		while r < m:
			run_prefix_sum_b += b[r]
			r += 1
		if prefix_sum_a > run_prefix_sum_b: return False

	sufix_sum_a = 0
	run_suffix_sum_b = 0
	l = n - 1
	for i in range(n - 1, -1, -1):
		sufix_sum_a += a[i]
		m = max(-1, i - k - 1)
		while l > m:
			run_suffix_sum_b += b[l]
			l -= 1
		if sufix_sum_a > run_suffix_sum_b: return False

	return True


n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
sum_a = sum(a)
sum_b = sum(b)
if sum_a > sum_b:
	print(-1)
else:
	l = 0
	r = n - 1
	while l <= r:
		k = l + (r - l) // 2
		if is_valid(n, a, b, k):
			r = k - 1
		else:
			l = k + 1
	print(r + 1)