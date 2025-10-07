def bs(events, b):
	l = 0
	r = len(events) - 1
	while l <= r:
		m = l + (r - l) // 2
		if events[m][1] <= b:
			l = m + 1
		else:
			r = m - 1
	return l

n = int(input())
events = [list(map(float, input().split())) for _ in range(n)] # b, e, w
events.sort(key=lambda x: x[1])
dp = [0.0] * (n + 1)
for i in range(n):
	j = bs(events, events[i][0])
	take = dp[j] + events[i][2]
	skip = dp[i]
	dp[i + 1] = max(take, skip)
print(dp[n])