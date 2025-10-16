n, w, h = map(int, input().split())
rects = [[0, 0] for _ in range(n)]

max_a = 0
max_b = 0
for i in range(n):
	a, b = map(int, input().split())
	rects[i][0] = a
	rects[i][1] = b
	max_a = max(max_a, a)
	max_b = max(max_b, b)

def is_valid(k):
	curr_w = rects[0][0] * k
	curr_h = rects[0][1] * k
	for i in range(1, n):
		curr_new_a = rects[i][0] * k
		curr_new_b = rects[i][1] * k
		if rects[i - 1][1] == rects[i][1] and curr_w + curr_new_a <= w:
			curr_w += curr_new_a
		else:
			curr_w = curr_new_a
			curr_h += curr_new_b
	return curr_h <= h

l = 0.0
r = min(w / max_a, h / max_b)
while l <= r:
	k = l + (r - l) / 2.0
	if is_valid(k):
		l = k + 0.0000001
	else:
		r = k - 0.0000001
print(r)