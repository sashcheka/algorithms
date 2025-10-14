a, b, s = map(int, input().split())
ans = -1
l = max(a, b)
r = 1_000_000
while l <= r:
	m = l + (r - l) // 2
	cand_a = m - a
	cand_b = m - b
	cand_s = cand_a * cand_b
	if cand_s == s:
		ans = m
		break
	elif cand_s > s:
		r = m - 1
	elif cand_s < s:
		l = m + 1
print(ans)