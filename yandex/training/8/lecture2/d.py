s = input()
n = int(input())
words = [input() for _ in range(n)]
m = len(s)
space = [-1] * (m + 1)
space[0] = 0
for i in range(m):
	for word in words:
		if i + len(word) > m or s[i] != word[0]: continue
		if s[i : i + len(word)] == word and space[i + len(word)] == -1:
			space[i + len(word)] = i
ans = []
pos = m
while pos != 0:
	nxt = space[pos]
	ans.append(s[nxt:pos])
	pos = nxt
ans.reverse()
print(*ans)