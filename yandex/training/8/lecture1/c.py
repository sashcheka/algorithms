s = input()
dupa = {}
ans = 1
for ch in s:
	for key, cnt in dupa.items():
		if ch == key: continue
		ans += cnt
	dupa[ch] = dupa.get(ch, 0) + 1
print(ans)