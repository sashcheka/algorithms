def find(idx):
	while idx != parent[idx]:
		parent[idx] = parent[parent[idx]]
		idx = parent[idx]
	return idx


def union(u, v):
	u_parent = find(u)
	v_parent = find(v)
	parent[v_parent] = u_parent


n, m, k = map(int, input().split())
parent = [i for i in range(n)]
edges = [() for _ in range(m)]

for i in range(m):
	u, v = map(int, input().split())
	edges[i] = (u - 1, v - 1)

operations = [() for _ in range(k)]

for i in range(k):
	line = list(input().split())
	cmd = line[0]
	u = int(line[1]) - 1
	v = int(line[2]) - 1
	operations[i] = (cmd, u, v)

operations.reverse()

result = []
for oper in operations:
	cmd, u, v = oper

	if cmd == "ask":
		if find(u) == find(v):
			result.append("YES")
		else:
			result.append("NO")
	elif cmd == "cut":
		union(u, v)

result.reverse()
print(*result, sep='\n')