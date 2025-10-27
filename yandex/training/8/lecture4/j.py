n, l, w = map(int, input().split())
x = [0] * n
y = [0] * n
vx = [0] * n
vy = [0] * n
for i in range(n):
    x[i], y[i], vx[i], vy[i] = map(int, input().split())

DIFF = 1e-9
wall = [None] * n
finish = [None] * n
for i in range(n):
    if vy[i] > 0: wall[i] = (w - y[i]) / vy[i]
    elif vy[i] < 0: wall[i] = (0 - y[i]) / vy[i]
    else: wall[i] = None

    if vx[i] > 0:
        t = (l - x[i]) / vx[i]
        yf = y[i] + vy[i] * t
        if t >= -DIFF and (yf > DIFF) and (yf < w - DIFF): finish[i] = t
        else: finish[i] = None
    else:
        finish[i] = None

tl = [wall[i] if (finish[i] is None or (wall[i] is not None and wall[i] < finish[i] - DIFF)) else finish[i] for i in range(n)]

events = []  # time, type, idx
for i in range(n):
    if wall[i] is not None: events.append([wall[i], 'w', i])
    if finish[i] is not None: events.append([finish[i], 'f', i])

for i in range(n):
    xi, yi, vxi, vyi = x[i], y[i], vx[i], vy[i]
    for j in range(i + 1, n):
        dx = xi - x[j]
        dy = yi - y[j]
        dvx = vxi - vx[j]
        dvy = vyi - vy[j]

        if dvx == 0 and dvy == 0: continue

        t = None
        if dvx == 0:
            if dx != 0: continue
            if dvy == 0: continue
            t = -(dy) / dvy
        elif dvy == 0:
            if dy != 0: continue
            t = -(dx) / dvx
        else:
            if dx * dvy != dy * dvx: continue
            t = -(dx) / dvx

        if t < -DIFF: continue

        if (tl[i] is None or t <= tl[i] + DIFF) and (tl[j] is None or t <= tl[j] + DIFF):
            events.append([t, 'c', (i, j)])

if not events:
    print(0)
else:
    events.sort(key=lambda event: event[0])
    valid = [True] * n
    i = 0
    m = len(events)
    while i < m:
        T = events[i][0]
        coll, walls, fins = [], [], []
        while i < m and abs(events[i][0] - T) <= DIFF:
            tp = events[i][1]
            pl = events[i][2]
            if tp == 'c': coll.append(pl)
            elif tp == 'w': walls.append(pl)
            else: fins.append(pl)
            i += 1

        collided = set()
        for a, b in coll:
            if valid[a] and valid[b]:
                collided.add(a); 
                collided.add(b)
        
        for a in walls:
            if valid[a]: collided.add(a)
        
        for a in collided:
            valid[a] = False

        win = []
        for a in fins:
            if valid[a]: win.append(a)

        if win:
            win.sort()
            print(len(win))
            print(' '.join(str(a + 1) for a in win))
            break
    else:
        print(0)
        print()