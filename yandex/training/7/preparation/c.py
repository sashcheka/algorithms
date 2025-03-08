def main():
    n = int(input())
    carns = sorted(map(int, input().split()))

    if n == 2:
        print(carns[1] - carns[0])
        return

    dp = [0] * n
    dp[0] = carns[1] - carns[0]
    dp[1] = dp[0]

    for i in range(2, n):
        dp[i] = min(dp[i - 1], dp[i - 2]) + carns[i] - carns[i - 1]

    print(dp[n - 1])
    return


if __name__ == '__main__':
    main()