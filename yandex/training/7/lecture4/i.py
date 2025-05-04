n = int(input())

head = [0] * (n + 1)
prev = [-1] * (n + 1)

curr_weight = [0] * (n + 1)
total = [0] * (n + 1)

mass = 0

for i in range(1, n + 1):
    t, m = map(int, input().split())

    if m != 0:
        head[i] = i
        prev[i] = head[t]
        curr_weight[i] = m
        total[i] = total[t] + m
    else:
    	head[i] = prev[head[t]]
    	prev[i] = prev[head[i]]
    	total[i] = total[t] - curr_weight[head[t]]

    mass += total[i]

print(mass)