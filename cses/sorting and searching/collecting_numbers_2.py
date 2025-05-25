n, m = map(int, input().split())
nums = list(map(int, input().split()))
pos = [0] * n
for i in range(n):
    pos[nums[i] - 1] = i

rounds = 1
for i in range(n - 1):
    if pos[i] > pos[i + 1]:
        rounds += 1

out = []
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1

    v, u = nums[a], nums[b]
    v -= 1
    u -= 1

    affected = {v - 1, v, u - 1, u}
    before = 0
    for i in affected:
        if 0 <= i < n - 1 and pos[i] > pos[i + 1]:
            before += 1

    nums[a], nums[b] = nums[b], nums[a]
    pos[v], pos[u] = pos[u], pos[v]

    after = 0
    for i in affected:
        if 0 <= i < n - 1 and pos[i] > pos[i + 1]:
            after += 1

    rounds += after - before
    out.append(rounds)

print(*out, sep='\n')