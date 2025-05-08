def find(node):
	root = node
	while dsu[root] != root:
		root = dsu[root]
	while dsu[node] != node:
		nxt = dsu[node]
		dsu[node] = root
		node = nxt
	return root

def union(x, y):
	root_x = find(x)
	root_y = find(y)
	if root_x != root_y:
		if dsu_rank[root_x] < dsu_rank[root_y]:
			root_x, root_y = root_y, root_x
		dsu[root_y] = root_x
		if dsu_rank[root_x] == dsu_rank[root_y]:
			dsu_rank[root_x] += 1
		return True
	return False

n, m = map(int, input().split())
dsu = list(range(n + 1))
dsu_rank = [0] * (n + 1)
ans = n
for i in range(1, m + 1):
	x, y = map(int, input().split())
	if union(x, y):
		ans -= 1
	if ans == 1:
		print(i)
		break