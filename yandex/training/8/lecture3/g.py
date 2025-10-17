def bs(sorted_list, val):
	l = 0
	r = len(sorted_list) - 1
	while l <= r:
		m = l + (r - l) // 2
		if sorted_list[m] <= val:
			l = m + 1
		else:
			r = m - 1
	return l

def calc(sorted_list, prefix, val):
	r = len(sorted_list)
	l = bs(sorted_list, val)
	res = (val * l - prefix[l]) + (prefix[r] - prefix[l] - val * (r - l))
	return res

n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

sorted_a = sorted(a)
sorted_b = sorted(b)

prefix_a = [0] * (n + 1)
prefix_b = [0] * (m + 1)
for i in range(1, n + 1): prefix_a[i] = prefix_a[i - 1] + sorted_a[i - 1]
for i in range(1, m + 1): prefix_b[i] = prefix_b[i - 1] + sorted_b[i - 1]

sum_a = 0
for i in range(n): sum_a += i * calc(sorted_b, prefix_b, a[i])
sum_b = 0
for j in range(m): sum_b += j * calc(sorted_a, prefix_a, b[j])

ans = sum_a - sum_b
print(ans)