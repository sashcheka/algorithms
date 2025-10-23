n, m, k = map(int, input().split())
a = list(map(int, input().split()))
events = [0] * (n + 1)
for i in range(m):
	l, r = map(int, input().split())
	l -= 1
	r -= 1
	events[l] += 1
	events[r + 1] -= 1
total_discomfort = 0
places_to_fix = []
for i in range(n):
	events[i + 1] += events[i]
	places_to_fix.append((events[i], i))
	total_discomfort += events[i] * a[i]
places_to_fix.sort(key=lambda x: x[0], reverse=True)
i = 0
while k > 0 and i < len(places_to_fix):
	overlaps = places_to_fix[i][0]
	idx = places_to_fix[i][1]
	to_fix = min(a[idx], k)
	k -= to_fix
	total_discomfort -= overlaps * to_fix
	i += 1
print(total_discomfort)