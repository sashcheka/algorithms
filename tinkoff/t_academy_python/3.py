n = int(input())
s = input()
left = [-1]*(n+1)
right = [-1]*(n+1)
head = 0
for i in range(1, n+1):
    ch = s[i-1]
    prev = i-1
    if ch == 'L':
        prev_left = left[prev]
        left[i] = prev_left
        right[i] = prev
        left[prev] = i
        if prev_left == -1:
            head = i
        else:
            right[prev_left] = i
    elif ch == 'R':
        prev_right = right[prev]
        left[i] = prev
        right[i] = prev_right
        right[prev] = i
        if prev_right != -1:
            left[prev_right] = i
ans = []
curr = head
while curr != -1:
    ans.append(str(curr))
    curr = right[curr]
print(*ans, sep=' ')