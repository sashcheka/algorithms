def main():
	t = int(input())

	for _ in range(t):
		question = list(input().split())
		target = question[:-1][:-1]

		ages = {}
		n = 3

		for _ in range(n):
			fact = list(input().split())
			a = fact[0]
			years = fact[2]

			if len(fact) == 5: # Aj is X years old
				ages[a] = years
			elif "same" in fact:
				b = fact[6]
				ages[a] = ages[b]
			elif "younger" in fact:

			elif "older" in fact:




if __name__ == "__main__":
	main()