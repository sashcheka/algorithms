def main():
    n, s = map(int, input().split())

    total_volume = 0
    items = []
    max_pressure = 0

    for i in range(n):
        v, c, p = map(int, input().split())
        total_volume += v
        max_pressure = max(max_pressure, p)
        items.append((v, c, p, i))

    cap = min(total_volume, s + max_pressure)
    items.sort(key=lambda x: x[2], reverse=True)

    dp = [[-1, max_pressure, []] for _ in range(cap + 1)] # cost, pressure, path[]
    dp[0] = [0, 0, []]

    for v, c, p, i in items:
        for curr_vol in range(min(cap, s + p), v - 1, -1):
            if dp[curr_vol - v][0] == -1:
                continue

            new_cost = dp[curr_vol - v][0] + c
            if new_cost > dp[curr_vol][0]:
                if curr_vol <= s + p:
                    dp[curr_vol][0] = new_cost
                    dp[curr_vol][1] = p
                    dp[curr_vol][2] = dp[curr_vol - v][2] + [i + 1]

    max_cost = 0
    path = []
    for i in range(cap + 1):
        if dp[i][0] > max_cost:
            max_cost = dp[i][0]
            path = dp[i][2]

    print(len(path), max_cost)
    print(*path)


if __name__ == '__main__':
    main()