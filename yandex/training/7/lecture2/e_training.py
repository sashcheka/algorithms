def update(tree, idx):
    while idx > 0:
        idx = (idx - 1) // 2
        left = tree[2 * idx + 1]
        right = tree[2 * idx + 2]
        tree[idx] = left + right


def query(tree, idx, tl, tr, l, r, k):
    if tr < l or tl > r:
        return (0, -1)

    if l <= tl and tr <= r:
        total = tree[idx]
        if total < k:
            return (total, -1)
        if tl == tr:
            return (total, tl)

    tm = (tl + tr) // 2
    left = 2 * idx + 1
    right = 2 * idx + 2

    left_count, left_pos = query(tree, left, tl, tm, l, r, k)
    if left_pos != -1:
        return (left_count, left_pos)

    right_count, right_pos = query(tree, right, tm + 1, tr, l, r, k - left_count)
    return (left_count + right_count, right_pos)


def build(tree, size, nums):
    for i in range(len(nums)):
        tree[size - 1 + i] = 1 if nums[i] == 0 else 0

    for i in range(size - 2, -1, -1):
        left = tree[2 * i + 1]
        right = tree[2 * i + 2]
        tree[i] = left + right


def main():
    n = int(input())
    nums = list(map(int, input().split()))

    p = 0
    while (1 << p) < n:
        p += 1
    size = 1 << p
    tree = [0] * (2 * size - 1)
    build(tree, size, nums)

    result = []
    k = int(input())
    for _ in range(k):
        line = list(input().split())
        if line[0] == 's':
            l, r, kth = int(line[1]), int(line[2]), int(line[3])
            l -= 1
            r -= 1
            _, idx = query(tree, 0, 0, size - 1, l, r, kth)
            result.append(idx + 1 if idx != -1 else -1)
        else:
            idx, v = int(line[1]), int(line[2])
            pos = size - 1 + (idx - 1)
            tree[pos] = 1 if v == 0 else 0
            update(tree, pos)

    print(*result)


if __name__ == "__main__":
    main()