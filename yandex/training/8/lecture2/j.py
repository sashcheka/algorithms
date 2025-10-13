import sys
sys.setrecursionlimit(1_000_000)

n, l = map(int, input().split())
P = 0
R = 1
Q = 2
F = 3
shop = [[0, 0, 0, 0] for _ in range(n)]
total = 0
for i in range(n):
	shop[i] = list(map(int, input().split()))
	total += shop[i][F]

if total < l:
	print(-1)
else:
	INF = float("inf")
	memo = {}

	def go(i, need):
		if need <= 0: return 0
		if i == n: return INF
		key = (i, need)
		if key in memo: return memo[key]
		p = shop[i][P]
		r = shop[i][R]
		q = shop[i][Q]
		f = shop[i][F]
		res = INF
		for j in range(f + 1):
			c = (j * p) if j < r else (j * q)
			val = c + go(i + 1, max(0, need - j))
			if val < res: res = val
		memo[key] = res
		return res

	min_cost = go(0, l)

	ans = [0] * n
	need = l
	for i in range(n):
		if need <= 0: break
		p = shop[i][P]
		r = shop[i][R]
		q = shop[i][Q]
		f = shop[i][F]
		best = go(i, need)
		for j in range(f + 1):
			c = (j * p) if j < r else (j * q)
			if c + go(i + 1, max(0, need - j)) == best:
				ans[i] = j
				need -= j
				if need < 0: need = 0
				break

	if min_cost >= INF:
		print(-1)
	else:
		print(min_cost)
		print(*ans)