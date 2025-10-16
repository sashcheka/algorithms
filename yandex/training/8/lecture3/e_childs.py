n = int(input())
children = [[] for _ in range(n)]
for i in range(1, n):
    p = int(input())
    children[p].append(i)

a = list(map(int, input().split()))

ans = 0
for u in range(n):
    children_value = 0
    for v in children[u]:
        children_value += a[v]
    ans += abs(children_value - a[u])

print(ans)