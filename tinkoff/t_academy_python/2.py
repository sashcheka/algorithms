s = input()
a = 0
b = 0
c = 0
ans = 0
for ch in s:
    if ch == 'a':
        a += 1
    elif ch == 'b':
        b += a
    elif ch == 'c':
        c += b
ans = c
print(ans)