n = int(input())
a = list(map(int, input().split()))
sum_l = 0
sum_r = 0
diff = float("inf")
l_best = 0
r_best = n - 1
l = 0
r = n - 1
while l <= r:
	if sum_l < sum_r:
		sum_l += a[l]
		l += 1
	else:
		sum_r += a[r]
		r -= 1
	if l != 0 and r != n - 1 and l - 1 < r + 1:
		if abs(sum_l - sum_r) < diff:
			diff = abs(sum_l - sum_r)
			l_best = l - 1
			r_best = r + 1
print(diff, l_best + 1, r_best + 1)