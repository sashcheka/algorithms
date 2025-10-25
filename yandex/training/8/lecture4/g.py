n = int(input())
s = list(map(int, input().split()))
a = list(map(int, input().split()))
a_sum = sum(a)
half = a_sum / 2
pairs = [[s[i], a[i]] for i in range(n)]
pairs.sort()
run_sum = 0
series_cnt = 0
for i in range(n):
	run_sum += pairs[i][1]
	if run_sum >= half:
		series_cnt = pairs[i][0]
		break
cost = 0
for i in range(n): 
	cost += abs(series_cnt - s[i]) * a[i]
print(series_cnt, cost)