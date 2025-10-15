import sys
sys.setrecursionlimit(1_000_000)

n = int(input())
parent = list(map(int, input().split()))

children = [[] for _ in range(n)]
root = -1
for i in range(n):
    if parent[i] == 0:
        root = i
    else:
        children[parent[i] - 1].append(i)

time_in = [0] * n
time_out = [0] * n
time = 0

def dfs(u):
    global time
    time += 1
    time_in[u] = time
    for v in children[u]:
        dfs(v)
    time += 1
    time_out[u] = time

dfs(root)

m = int(input())
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    if time_in[a] <= time_in[b] and time_out[b] <= time_out[a]:
        print(1)
    else:
        print(0)