from collections import OrderedDict

n = int(input())
books = [[] for _ in range(n)]
for i in range(n):
	book = list(map(str, input().split()))
	books[i] = book

dupa = {}
for title, genre, author in books:
	dupa.setdefault(genre, {}).setdefault(author, []).append(title)

ans = OrderedDict()
for genre in sorted(dupa):
	ans[genre] = OrderedDict()
	for author in sorted(dupa[genre]):
		ans[genre][author] = dupa[genre][author]

print(ans)


# 3
# КнигаА Жанр2 Автор1
# КнигаА Жанр1 Автор2
# КнигаА Жанр1 Автор1