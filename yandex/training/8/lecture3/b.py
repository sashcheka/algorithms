from collections import deque

n = int(input())
degree = [0] * (n + 1)
graph = [[] for _ in range(n + 1)]
for i in range(n - 1):
	a, b = map(int, input().split())
	degree[a] += 1
	degree[b] += 1
	graph[a].append(b)
	graph[b].append(a)
leaves = []
for i in range(1, n + 1):
	if degree[i] == 1: leaves.append(i)
q = deque()
source = [0] * (n + 1)
dist = [-1] * (n + 1)
for leaf in leaves:
    source[leaf] = leaf
    dist[leaf] = 0
    q.append(leaf)
ans = 0
while q:
    curr = q.popleft()
    source_curr = source[curr]
    dist_curr = dist[curr]
    for nxt in graph[curr]:
        source_next = source[nxt]
        if source_next == 0:
            source[nxt] = source_curr
            dist[nxt] = dist_curr + 1
            q.append(nxt)
        elif source_next != source_curr:
            ans = dist_curr + dist[nxt] + 1
            break
    if ans != 0: break
print(ans)