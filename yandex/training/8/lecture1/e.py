n, k = map(int, input().split())
dupa = {}
x = n
first = True
while k:
	rem = x % 10
	if rem in dupa: break
	x += rem
	if not first:
		dupa[rem] = x % 10
	first = False
	k -= 1
m = len(dupa)
total = 0
for val, _ in dupa.items():
	total += val
if k > 0:
	whole = k // len(dupa)
	x += total * whole
	rem = k % len(dupa)
	curr = x % 10
	while rem:
		x += curr
		curr = dupa[curr]
		rem -= 1
print(x)