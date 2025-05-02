from collections import deque


n = int(input())
banks = [0] * n
for i in range(n):
	banks[i] = int(input()) - 1

indegree = [0] * n
for key in banks:
	indegree[key] += 1

q = deque()
for i in range(n):
	if indegree[i] == 0:
		q.append(i)

seen = [False] * n
while q:
	curr = q.popleft()
	seen[curr] = True
	nxt = banks[curr]
	indegree[nxt] -= 1
	if indegree[nxt] == 0:
		q.append(nxt)

breaks = 0
for i in range(n):
	if seen[i]:
		continue

	breaks += 1
	curr = i
	while not seen[curr]:
		seen[curr] = True
		nxt = banks[curr]
		curr = nxt

print(breaks)