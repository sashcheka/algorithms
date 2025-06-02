def solve(strings):
	n = len(strings)
	if n == 0:
		return ""

	shortest = strings[0]
	for s in strings:
		if len(s) < len(shortest):
			shortest = s

	best_prefix = len(shortest)
	for i in range(1, n):
		s = strings[i]

		curr_prefix = 0
		for j in range(len(shortest)):
			if j < len(s) and s[j] == shortest[j]:
				curr_prefix += 1
			else:
				break

		best_prefix = min(best_prefix, curr_prefix)

	return shortest[0:best_prefix]


strings = ["flight", "flower", "flow", "flew"]
ans = solve(strings)
print(ans)