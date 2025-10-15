n = int(input())
parent = list(map(int, input().split()))
dupa = {}
m = int(input())
for i in range(m):
	a, b = map(int, input().split())
	a -= 1
	b -= 1
	if b not in dupa: dupa[b] = set()
	if a in dupa[b]:
		print(1)
		continue
	temp_b = b
	is_parent = False
	while temp_b != -1:
		if temp_b == a:
			is_parent = True
		dupa[b].add(temp_b)
		temp_b = parent[temp_b] - 1
	print(1 if is_parent else 0)