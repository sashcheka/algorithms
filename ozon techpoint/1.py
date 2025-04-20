def main():
	t = int(input())

	for _ in range(t):
		n = int(input())
		dupa = {}

		action = ""
		for _ in range(n):
			line = list(input().split())

			a, b, mine, point, x = "", "", True, 0, ""
			if len(line) == 4: # YES
				a = line[0][:-1]
				b = line[1]
				mine = True if line[2] == "am" else False
				point = 1
				x = line[3][:-1]
			elif len(line) == 5: # NO
				a = line[0][:-1]
				b = line[1]
				mine = True if line[2] == "am" else False
				point = -1
				x = line[4][:-1]

			if not action:
				action = x

			if mine:
				if a in dupa:
					dupa[a] += 2 * point
				else:
					dupa[a] = 2 * point
			else:
				if b in dupa:
					dupa[b] += point
				else:
					dupa[b] = point

		dupa_sorted = sorted(dupa.items(), key=lambda x: (-x[1], x[0]))
		max_score = dupa_sorted[0][1]
		cands = []	
		for key, value in dupa.items():
			if value == max_score:
				cands.append(key)

		cands.sort()
		for cand in cands:
			print(f"{cand} is {action}.")


if __name__ == "__main__":
	main()