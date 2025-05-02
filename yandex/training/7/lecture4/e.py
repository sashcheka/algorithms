from collections import deque


n = int(input())
ratings = list(map(int, input().split()))

prev = [(i - 1) for i in range(n)]
nxt = [(i + 1) % n for i in range(n)]

leave_turns = [0] * n
to_leave = [False] * n
seen = [False] * n
remain = n

q = deque()
for i in range(n):
	if ratings[prev[i]] > ratings[i] < ratings[nxt[i]]:
		to_leave[i] = True
		q.append((i, 1))

while q and remain > 2:
	idx, turn = q.popleft()

	if seen[idx]:
		continue

	seen[idx] = True
	leave_turns[idx] = turn
	remain -= 1

	l = prev[idx]
	r = nxt[idx]
	nxt[l] = r
	prev[r] = l

	if not seen[l] and not to_leave[l]:
		if ratings[prev[l]] > ratings[l] < ratings[nxt[l]]:
			to_leave[l] = True
			q.append((l, turn + 1))

	if not seen[r] and not to_leave[r]:
		if ratings[prev[r]] > ratings[r] < ratings[nxt[r]]:
			to_leave[r] = True
			q.append((r, turn + 1))


print(*leave_turns)