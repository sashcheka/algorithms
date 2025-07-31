from collections import deque

n, q = map(int, input().split())
adj = [[] for _ in range(n+1)]

for _ in range(q):
    l, r = map(int, input().split())
    adj[l-1].append(r)
    adj[r].append(l-1)

dist = [-1] * (n+1)
dist[0] = 0
q = deque()
q.append(0)

while q:
    v = q.popleft()
    if v == n:
        break
    for nxt in adj[v]:
        if dist[nxt] == -1:
            dist[nxt] = dist[v] + 1
            q.append(nxt)

if dist[n] == -1:
    print("No")
else:
    print("Yes")
    print(dist[n])
