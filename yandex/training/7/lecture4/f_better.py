n = int(input())
nxt = [0] * n
for i in range(n): nxt[i] = int(input()) - 1
component = [-1] * n
ans = 0
for i in range(n):
    if component[i] != -1: continue
    curr = i
    while component[curr] == -1:
        component[curr] = i
        curr = nxt[curr]
    if component[curr] == i: ans += 1
print(ans)