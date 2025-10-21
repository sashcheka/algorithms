n = int(input())
tax_rates = [[] for _ in range(n)]
for i in range(n): tax_rates[i] = list(map(int, input().split()))
m = int(input())
powers = [[] for _ in range(m)]
for i in range(m): powers[i] = [int(input()), i]
powers.sort(key=lambda x: x[0])
i = 0
ans = [0] * m
for j in range(m):
	while i < n - 1 and tax_rates[i + 1][0] < powers[j][0]: i += 1
	ans[powers[j][1]] = powers[j][0] * tax_rates[i][1]
print(*ans, sep='\n')