n, k = map(int, input().split())
a = list(map(int, input().split()))
dupa = {}
for t in a:
	dupa[t] = dupa.get(t, 0) + 1
ans = [0] * k
for t, cnt in dupa.items():
	if k <= 0: break
	ans[k - 1] = t
	k -= 1
if k > 0:
	for t, cnt in dupa.items():
		for i in range(cnt - 1):
			if k <= 0: break
			ans[k - 1] = t
			k -= 1
print(*ans)