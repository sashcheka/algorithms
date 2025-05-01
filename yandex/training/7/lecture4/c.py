deque = []

while True:
	line = list(input().split())
	cmd = line[0]

	if cmd == "push_front":
		n = line[1]
		deque.insert(0, n)
		print("ok")
	elif cmd == "push_back":
		n = line[1]
		deque.append(n)
		print("ok")
	elif cmd == "pop_front":
		if len(deque) > 0:
			print(deque.pop(0))
		else:
			print("error")
	elif cmd == "pop_back":
		if len(deque) > 0:
			print(deque.pop())
		else:
			print("error")
	elif cmd == "front":
		if len(deque) > 0:
			print(deque[0])
		else:
			print("error")
	elif cmd == "back":
		if len(deque) > 0:
			print(deque[-1])
		else:
			print("error")
	elif cmd == "size":
		print(len(deque))
	elif cmd == "clear":
		deque.clear()
		print("ok")
	elif cmd == "exit":
		print("bye")
		break