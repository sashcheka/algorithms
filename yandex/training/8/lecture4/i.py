n, d = map(int, input().split())
setik = set()
coords = [[] for _ in range(n)]
for i in range(n):
	coords[i] = tuple(map(int, input().split()))
	setik.add(coords[i])
cands = set()
for x in range(int(d ** 0.5) + 1):
	y_sqr = d - x * x
	y = int(y_sqr ** 0.5)
	if y * y != y_sqr: continue
	for dx, dy in [(x, y), (-x, y), (x, -y), (-x, -y), (y, x), (-y, x), (y, -x), (-y, -x)]:
		if dx > 0 or (dx == 0 and dy > 0):
			cands.add((dx, dy))
ans = 0
for x, y in coords:
	for dx, dy in cands:
		if (x + dx, y + dy) in setik: ans += 1
print(ans)