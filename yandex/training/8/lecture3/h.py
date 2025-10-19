import sys
sys.setrecursionlimit(1_000_000)

n = int(input())
a = list(map(int, input().split()))

adj = [[] for _ in range(n)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    adj[u].append(v)
    adj[v].append(u)

parent = [-1] * n
top_down_order = [0]
for u in top_down_order:
    for v in adj[u]:
        if v != parent[u]:
            parent[v] = u
            top_down_order.append(v)

bottom_up_order = reversed(top_down_order)
subtree_sum = [0] * n
for u in bottom_up_order:
    curr_sum = a[u]
    for v in adj[u]:
        if parent[v] == u:
            curr_sum += subtree_sum[v]
    subtree_sum[u] = curr_sum

total = subtree_sum[0]
best_u = -1
min_max_sum = float("inf")

for u in range(n):
    curr_max_sum = a[u]
    for v in adj[u]:
        if parent[v] == u:  # getting largest queue size from childs
            curr_max_sum = max(curr_max_sum, subtree_sum[v])
        else:
            curr_max_sum = max(curr_max_sum, total - subtree_sum[u])
    if curr_max_sum < min_max_sum:  # fixing min max queue size
        min_max_sum = curr_max_sum
        best_u = u

print(best_u + 1)