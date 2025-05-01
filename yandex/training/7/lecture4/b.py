queue = []

while True:
	line = list(input().split())
	cmd = line[0]

	if cmd == "push":
		n = line[1]
		queue.append(n)
		print("ok")
	elif cmd == "pop":
		if len(queue) > 0:
			print(queue.pop(0))
		else:
			print("error")
	elif cmd == "front":
		if len(queue) > 0:
			print(queue[0])
		else:
			print("error")
	elif cmd == "size":
		print(len(queue))
	elif cmd == "clear":
		queue.clear()
		print("ok")
	elif cmd == "exit":
		print("bye")
		break