def can_build_second_wall(dp, total_w, k):
    for w in range(1, total_w):
        if all(dp[color][w] for color in range(k)):
            return w
    return -1


def main():
    n, k = map(int, input().split())
    ls = [0] * n
    cs = [0] * n

    color_bricks = [[] for _ in range(k)]
    sum_width_per_color = [0] * k

    for i in range(n):
        l, c = map(int, input().split())
        c -= 1
        ls[i] = l
        cs[i] = c
        color_bricks[c].append((l, i + 1))
        sum_width_per_color[c] += l

    if len(set(sum_width_per_color)) != 1:
        print("NO")
        return

    max_pos_width = min(sum_width_per_color)
    dp = [[False] * (max_pos_width + 1) for _ in range(k)]
    path = [[[] for _ in range(max_pos_width + 1)] for _ in range(k)]

    for c in range(k):
        dp[c][0] = True

    for c in range(k):
        for l, idx in color_bricks[c]:
            for cand in range(max_pos_width, l - 1, -1):
                if dp[c][cand - l]:
                    dp[c][cand] = True
                    path[c][cand] = path[c][cand - l] + [idx]

    w = can_build_second_wall(dp, max_pos_width, k)

    if w == -1:
        print("NO")
        return
    else:
        print("YES")
        result = []
        for c in range(k):
            result.extend(path[c][w])
        print(*result)
        return


if __name__ == "__main__":
    main()