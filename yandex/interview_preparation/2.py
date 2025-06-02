def solve(nums, k):
	dupa = {}
	for num in nums:
		dupa[num] = dupa.get(num, 0) + 1
	dupa = dict(sorted(dupa.items(), key=lambda x: -x[1]))
	if len(dupa) < k:
		return [-1]
	ans = []
	for num in dupa.keys():
		if k == 0:
			break
		ans.append(num)
		k -= 1
	return ans

nums = [1, 1, 1, 2, 2, 3]
k = 2
ans = solve(nums, k)
print(*ans)