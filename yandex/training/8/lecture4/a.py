n = int(input())
events_f = [0] * 1440
events_s = [0] * 1440
for i in range(n):
	s = input()
	l = int(s[:2]) * 60 + int(s[3:5])
	r = int(s[6:8]) * 60 + int(s[9:])
	events_f[l] -= 1
	events_s[r] += 1
m = int(input())
for i in range(m):
	s = input()
	l = int(s[:2]) * 60 + int(s[3:5])
	r = int(s[6:8]) * 60 + int(s[9:])
	events_s[l] -= 1
	events_f[r] += 1
busses_f = 0
busses_s = 0
ans = 0
for i in range(1440):
	busses_f += events_f[i]
	busses_s += events_s[i]
	if busses_f < 0:
		ans += abs(busses_f)
		busses_f = 0
	if busses_s < 0:
		ans += abs(busses_s)
		busses_s = 0
print(ans)