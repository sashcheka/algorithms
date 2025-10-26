n = int(input())
a = list(map(int, input().split()))
events = [0] * n
for i in range(n):
	l = i + 1
	r = i + a[i]
	if l < n: events[l] += 1
	if r < n: events[r] -= 1
for i in range(1, n):
	events[i] += events[i - 1]
ans = 0
for i in range(n):
	ans += events[i] * a[i]
print(ans)