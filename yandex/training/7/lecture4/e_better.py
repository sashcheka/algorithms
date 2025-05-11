PREV = 0
RATING = 1
IDX = 2
NEXT = 3

SIZE = 0
HEAD = 1
TAIL = 2

def push_back(q, rating, idx):
	curr = [None, rating, idx, None]
	if q[SIZE] == 0:
		q[HEAD] = q[TAIL] = curr
	else:
		curr[PREV] = q[TAIL]
		q[TAIL][NEXT] = curr
		q[TAIL] = curr
	q[SIZE] += 1
	return

def delete(q, curr):
	prev = curr[PREV]
	nxt = curr[NEXT]
	ans[curr[IDX]] = leave_round[curr[IDX]] + 1
	leave_round[prev[IDX]] = max(leave_round[prev[IDX]], ans[curr[IDX]])
	leave_round[nxt[IDX]] = max(leave_round[nxt[IDX]], ans[curr[IDX]])
	prev[NEXT] = nxt
	nxt[PREV] = prev
	q[SIZE] -= 1
	return

q = [0, None, None]
n = int(input())
a = list(map(int, input().split()))
ans = [0] * n
leave_round = [0] * n
for idx, rating in enumerate(a):
	push_back(q, rating, idx)

q[TAIL][NEXT] = q[HEAD]
q[HEAD][PREV] = q[TAIL]

curr = q[HEAD]
last_upd = q[HEAD][IDX]

while True:
	if curr[PREV][RATING] > curr[RATING] < curr[NEXT][RATING] and curr[PREV] is not curr[NEXT]:
		delete(q, curr)
		curr = curr[PREV]
		last_upd = curr[IDX]
	else:
		curr = curr[NEXT]
		if curr[IDX] == last_upd:
			break
print(*ans)