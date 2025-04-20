def main():
	t = int(input())

	for _ in range(t):
		n, k = map(int, input().split())
		nums = list(map(int, input().split()))

		l = 0
		flag = True
		while l < n:
			sub = nums[l]
			nums[l] -= sub

			r = l + k
			l += 1
			temp = l

			while temp < n and temp < r:
				nums[temp] -= sub
				if nums[temp] < 0:
					flag = False
					break
				temp += 1

			if not flag:
				break
		
		print("YES" if flag else "NO")


if __name__ == "__main__":
	main()