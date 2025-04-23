n = int(input())

max_bit = 0
bit = 0
temp = n
while temp:
	if temp & 1:
		max_bit = bit
	bit += 1
	temp >>= 1

temp = n
if temp & 1:
	temp >>= 1
	temp |= 1 << max_bit
else:
	temp >>= 1
max_value = temp

while temp != n:
	if temp & 1:
		temp >>= 1
		temp |= 1 << max_bit
	else:
		temp >>= 1
	max_value = max(max_value, temp)

print(max_value)