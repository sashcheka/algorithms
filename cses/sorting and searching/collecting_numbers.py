n = int(input())
nums = list(map(int, input().split()))
check = [0] * n
for i in range(n):
	check[nums[i] - 1] = i
rounds = 1
for i in range(1, n):
	if check[i - 1] > check[i]:
		rounds += 1
print(rounds)