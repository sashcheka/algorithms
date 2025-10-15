n, p = map(int, input().split())
nums = list(map(int, input().split()))
c = [(0, 0) for _ in range(n)]
for i in range(n): c[i] = (nums[i], i)
c.sort(key=lambda x: x[0], reverse=True)
i_best = -1
j_best = -1
p_best = float("inf")
for i in range(n - 1):
	l = i + 1
	r = n - 1
	while l <= r:
		j = l + (r - l) // 2
		p_cand = c[i][0] / c[j][0]
		if p_cand - p == 0:
			i_best = c[i][1]
			j_best = c[j][1]
			p_best = p_cand - p
			break
		elif p_cand - p > 0:
			if abs(p_cand - p) < p_best:
				p_best = abs(p_cand - p)
				i_best = c[i][1]
				j_best = c[j][1]
			r = j - 1
		elif p_cand - p < 0:
			if abs(p_cand - p) < p_best:
				p_best = abs(p_cand - p)
				i_best = c[i][1]
				j_best = c[j][1]
			l = j + 1
	if p_best == p: break
print(i_best + 1, j_best + 1)