# 1
n = int(input())
lst = list(map(int, input().split()))
lst.sort()
ans = []
expect = 1
for num in lst:
	while expect <= n and num != expect:
		ans.append(expect)
		expect += 1
	if expect == num:
		expect += 1
print(*ans)


# 2
n = int(input())
lst = list(map(int, input().split()))
setik = set(range(1, n + 1))
lst = list(setik - set(lst))
print(*lst)