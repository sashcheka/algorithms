from queue import Queue

n = int(input())
parent = [0] * n
degree = [0] * n
for i in range(1, n):
	p = int(input())
	parent[i] = p
	degree[i] += 1
	degree[p] += 1
a = list(map(int, input().split()))
q = Queue()
for i in range(1, n):
	if degree[i] == 1:
		q.put(i)

val = [0] * n

ans = 0
while not q.empty():
	u = q.get()
	p = parent[u]
	ans += abs(a[u] - val[u])
	val[p] += a[u]
	degree[u] -= 1
	degree[p] -= 1
	if p != 0 and degree[p] == 1: q.put(p)

print(ans + abs(a[0] - val[0]))