def main():
    n = int(input())
    dp = [[[float("inf"), []] for _ in range(n + 1)] for _ in range(n + 1)] # price, coupons use path
    dp[0][0] = [0, []]

    for i in range(n):
        price = int(input())
        for j in range(n):
            if dp[i][j][0] == float("inf"):
                continue

            if j >= 1 and dp[i][j][0] < dp[i + 1][j - 1][0]:
                dp[i + 1][j - 1][0] = dp[i][j][0]
                dp[i + 1][j - 1][1] = dp[i][j][1] + [1] # use a coupon

            if price <= 100 and dp[i][j][0] + price < dp[i + 1][j][0]:
                dp[i + 1][j][0] = dp[i][j][0] + price
                dp[i + 1][j][1] = dp[i][j][1] + [0] # don't use a coupon

            if price > 100 and dp[i][j][0] + price < dp[i + 1][j + 1][0]:
                dp[i + 1][j + 1][0] = dp[i][j][0] + price
                dp[i + 1][j + 1][1] = dp[i][j][1] + [0] # don't use a coupon
            
    min_spend = float("inf")
    remain_coupons = 0
    path = []
    for j in range(n + 1):
        if dp[n][j][0] < min_spend:
            min_spend = dp[n][j][0]
            path = dp[n][j][1]
            remain_coupons = j
        elif dp[n][j][0] == min_spend and j > remain_coupons:
            path = dp[n][j][1]
            remain_coupons = j
    print(min_spend)

    used_coupons = 0
    days = []
    for i in range(len(path)):
        if path[i] == 1:
            used_coupons += 1
            days.append(i + 1)

    print(remain_coupons, used_coupons)
    for day in days:
        print(day)


if __name__ == '__main__':
    main()