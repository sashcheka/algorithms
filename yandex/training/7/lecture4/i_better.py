n = int(input())
prev = [0] * (n + 1)
size = [0] * (n + 1)
ans = 0
for i in range(1, n + 1):
	t, m = map(int, input().split())
	if m != 0:
		prev[i] = t
		size[i] = size[t] + m
	else:
		prev[i] = prev[prev[t]]
		size[i] = size[prev[t]]
	ans += size[i]
print(ans)