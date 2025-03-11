def main():
    n, m = map(int, input().split())
    matrix = [0] * n

    for i in range(n):
        row = list(map(int, input().split()))
        matrix[i] = row

    dp = [[(float("-inf"), [])] * (m + 1) for _ in range(n + 1)] # inf, path[]
    dp[0][0] = (0, [])

    for i in range(n):
        for j in range(m):
            # RIGHT
            if dp[i][j][0] + matrix[i][j] > dp[i + 1][j][0]:
                val = dp[i][j][0] + matrix[i][j]
                path = dp[i][j][1] + ['R']
                dp[i + 1][j] = (val, path)

            # DOWN
            if dp[i][j][0] + matrix[i][j] > dp[i][j + 1][0]:
                val = dp[i][j][0] + matrix[i][j]
                path = dp[i][j][1] + ['D']
                dp[i][j + 1] = (val, path)

    print(dp[n - 1][m][0])
    print(*dp[n - 1][m][1][0:-1])
    return


if __name__ == '__main__':
    main()