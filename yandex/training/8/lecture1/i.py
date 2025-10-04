x, y = map(int, input().split())
f, g = map(int, input().split())

diff_x = abs(x - f)
diff_y = abs(y - g)

if x == f and y == g:
	print(0)
elif diff_x + diff_y == 1:
	print(1)
elif diff_x == 0 or diff_y == 0:
	print((max(0, diff_x - 1) + max(0, diff_y - 1)) * 3)
else:
	print((max(0, diff_x - 1) + max(0, diff_y - 1)) * 3 + 1)