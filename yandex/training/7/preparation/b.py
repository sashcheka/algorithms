def main():
    n = int(input())

    prices = []
    for i in range(n):
        price = tuple(map(int, input().split()))
        prices.append(price)

    dp = [float("inf")] * (n + 1)
    dp[0] = 0

    for i in range(n):
        dp[i + 1] = min(dp[i + 1], dp[i] + prices[i][0])

        if i + 1 < n:
            dp[i + 2] = min(dp[i + 2], dp[i] + prices[i][1])

        if i + 2 < n:
            dp[i + 3] = min(dp[i + 3], dp[i] + prices[i][2])


    print(dp[n])
    return


if __name__ == '__main__':
    main()