class Node:
    def __init__(self, length):
        self.length = length
        self.prev = None
        self.next = None


n = int(input())
a = list(map(int, input().split()))
k = int(input())

nodes = [Node(l) for l in a]
for i in range(n):
    if i > 0:          
    	nodes[i].prev = nodes[i - 1]
    if i < n - 1:        
    	nodes[i].next = nodes[i + 1]
head = nodes[0]

square_sum = sum(l**2 for l in a)
print(square_sum)

curr = head
idx = 0

for _ in range(k):
    e, v = map(int, input().split())
    v -= 1

    diff = v - idx
    if diff > 0:
        for _ in range(diff):
            curr = curr.next
    elif diff < 0:
        for _ in range(-diff):
            curr = curr.prev
    idx = v

    target = curr.length
    square_sum -= target**2

    l = curr.prev
    r = curr.next

    if e == 1:
        if not l and r:
            square_sum -= r.length**2

            r.length += target
            square_sum += r.length**2
        elif l and not r:
            square_sum -= l.length**2

            l.length += target
            square_sum += l.length**2
        elif l and r:
            square_sum -= l.length**2
            square_sum -= r.length**2

            half_1 = target // 2
            half_2 = target - half_1

            l.length += half_1
            square_sum += l.length**2
            r.length += half_2
            square_sum += r.length**2

        if l: 
        	l.next = r
        if r: 
        	r.prev = l

        if r:
            curr = r
        elif l:
            curr = l
            idx -= 1
    else:
        half_1 = target // 2
        half_2 = target - half_1

        curr.length = half_1
        new_node = Node(half_2)

        old_next = curr.next
        curr.next = new_node
        new_node.prev = curr
        new_node.next = old_next

        if old_next:
            old_next.prev = new_node

        square_sum += half_1**2 + half_2**2

    print(square_sum)