def main():
    N, M = map(int, input().split())
    ms = list(map(int, input().split()))
    cs = list(map(int, input().split()))

    dp_ms = [False] * (M + 1)
    dp_ms[0] = True

    dp_cs = [0] * (M + 1)

    path = [[]] * (M + 1)
    
    for i in range(N):
        m = ms[i]
        c = cs[i]

        for cand in range(M, m - 1, -1):
            if dp_ms[cand - m]:
                dp_ms[cand] = dp_ms[cand - m]
                if dp_cs[cand - m] + c > dp_cs[cand]:
                    dp_cs[cand] = dp_cs[cand - m] + c
                    path[cand] = path[cand - m] + [i + 1]

    idx = -1
    result = 0
    for i in range(M, -1, -1):
        if dp_ms[i] and dp_cs[i] > result:
            result = dp_cs[i]
            idx = i

    print(*path[idx], sep='\n')
    return


if __name__ == "__main__":
    main()