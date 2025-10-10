n = int(input())
is_prime = [True] * (n + 1)
is_prime[0] = is_prime[1] = False
for i in range(2, int((n + 1) ** 0.5) + 1):
	if is_prime[i]:
		for j in range(i*i, n + 1, i):
			is_prime[j] = False
dp = [0] * (n + 1)
dp[0] = 2
for i in range(1, n + 1):
	player = 2
	for j in range(1, 4):
		k = i - j
		if k < 0: continue
		if not is_prime[k] and dp[k] == 2:
			player = 1
			break
	dp[i] = player
print(dp[n])