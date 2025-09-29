n = int(input())
nums = list(map(int, input().split()))
ans = 0
max_vasya = float("inf")
max_masha = 0
for i in range(n):
	if i % 2 == 0:
		ans += nums[i]
		max_vasya = min(max_vasya, nums[i])
	elif i % 2 == 1:
		ans -= nums[i]
		max_masha = max(max_masha, nums[i])
if max_masha - max_vasya > 0:
	ans += 2*(max_masha - max_vasya)
print(ans)