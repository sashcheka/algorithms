n, m, x = map(int, input().split())

events = []
for i in range(n): 
	a, b, v = map(int, input().split())
	start = (x - b) / v if a < b else (b - x) / v
	end = (x - a) / v if a < b else (a - x) / v
	if end >= 0: events.append([start, end])
events.sort()

merged_events = []
for i in range(len(events)):
	if len(merged_events) == 0 or events[i][0] > merged_events[-1][1]:
		merged_events.append([events[i][0], events[i][1]])
	else:
		merged_events[-1][1] = max(merged_events[-1][1], events[i][1])

t = list(map(int, input().split()))
times = [() for _ in range(m)]
for i in range(m): times[i] = (t[i], i)
times.sort()

i = 0
ans = [0] * m
prev_end = 0
for time, idx in times:
	while i < len(merged_events) and time > merged_events[i][1]: i += 1
	if i == len(merged_events) or time < merged_events[i][0]: ans[idx] = time
	else: ans[idx] = merged_events[i][1]

print(*ans, sep='\n')