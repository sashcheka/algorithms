def is_valid(n, a, b, k, sum_a):
    if k >= n - 1: return True

    i = 0
    remain = 0
    left = sum_a

    for j in range(n):
        lo = max(0, j - k)
        hi = min(n - 1, j + k)

        while i < lo:
            if remain == 0: remain = a[i]
            if remain > 0: return False
            remain = 0
            i += 1

        cap = b[j]
        while cap > 0 and i <= hi:
            if remain == 0: remain = a[i]
            take = min(cap, remain)
            remain -= take
            cap -= take
            left -= take
            if remain == 0: i += 1

    return left == 0


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
		if is_valid(n, a, b, k, sum_a):
			r = k - 1
		else:
			l = k + 1
	print(r + 1)