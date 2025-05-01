n = int(input())
cq = []

for _ in range(n):
	line = str(input())
	cmd = line[0:3]

	if cmd == "Run":
		cq.append(line[4:])
	elif cmd == "Alt":
		count = 0
		for ch in line[3:]:
			if ch == '+':
				count += 1
		idx = len(cq) - 1 - count % len(cq)
		target = cq[idx]
		cq.pop(idx)
		cq.append(target)

	print(cq[-1])