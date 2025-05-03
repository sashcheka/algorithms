def find(idx):
	if parent[idx] == idx:
		return idx
	parent[idx] = find(parent[idx])
	return parent[idx]


def union(u, v):
	u_parent = find(u)
	v_parent = find(v)
	parent[v_parent] = u_parent


n, m = map(int, input().split())
parent = [i for i in range(n)]
components = n
ans = -1

for bridge in range(m):
	u, v = map(int, input().split())
	u -= 1
	v -= 1

	if find(u) != find(v):
		union(u, v)
		components -= 1

	if components == 1 and ans == -1:
		ans = bridge + 1

print(ans)