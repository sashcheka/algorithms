import math


def build_sparse_table(nums):
    n = len(nums)
    _pow = int(math.log2(n)) + 1
    table = [[0] * n for _ in range(_pow)]

    for i in range(n):
        table[0][i] = nums[i]

    for i in range(1, _pow):
        for j in range(n - (1 << i) + 1):
            table[i][j] = max(table[i - 1][j], table[i - 1][j + (1 << (i - 1))])

    return table


def build_logs(n):
    pows = [0] * (n + 1)
    for i in range(2, n + 1):
        pows[i] = pows[i // 2] + 1
    return pows


def query_max(table, logs, l, r):
    length = r - l + 1
    j = logs[length]
    return max(table[j][l], table[j][r - (1 << j) + 1])


def main():
    n = int(input())
    nums = list(map(int, input().split()))

    sparse_table = build_sparse_table(nums)
    logs = build_logs(n)

    k = int(input())
    queries = []
    max_values_needed = set()

    for _ in range(k):
        l, r = map(int, input().split())
        l -= 1
        r -= 1
        max_val = query_max(sparse_table, logs, l, r)
        queries.append((l, r, max_val))
        max_values_needed.add(max_val)

    prefix = {val: [0] * (n + 1) for val in max_values_needed}
    for i in range(n):
        for val in prefix:
            prefix[val][i + 1] = prefix[val][i]
        if nums[i] in prefix:
            prefix[nums[i]][i + 1] += 1

    for l, r, max_val in queries:
        count = prefix[max_val][r + 1] - prefix[max_val][l]
        print(max_val, count)


if __name__ == "__main__":
    main()
