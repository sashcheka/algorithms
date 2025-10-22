n, x = map(int, input().split())
a = list(map(int, input().split()))
prefix = [0] * (n + 1)
for i in range(1, n + 1): prefix[i] = prefix[i - 1] + 1 if a[i - 1] >= x else prefix[i - 1]
m = int(input())
i = 0
for q in range(m):
	cmd = list(map(int, input().split()))
	if cmd[0] == 1: prefix.append(prefix[-1] + 1 if cmd[1] >= x else prefix[-1])
	elif cmd[0] == 2: i += 1
	elif cmd[0] == 3: print(prefix[i + cmd[1]] - prefix[i])