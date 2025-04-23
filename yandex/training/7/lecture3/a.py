x = int(input())
ones = 0
while x:
	if x & 1:
		ones += 1
	x >>= 1
print(ones)