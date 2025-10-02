n, m = map(int, input().split())
k = n // m
s = input()
dupa = {}
for i in range(m):
	t = input()
	if t in dupa:
		dupa[t].add(i + 1)
	else:
		dupa[t] = {i + 1}
ans = [0] * m
for i in range(m):
	t = s[i * k : (i + 1) * k]
	idx = dupa[t].pop()
	ans[i] = idx
print(*ans)