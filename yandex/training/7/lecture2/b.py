def query(tree, idx, tl, tr, l, r):
    if l > r:
        return [0, 0]

    if l == tl and r == tr:
        return tree[idx]

    tm = tl + (tr - tl) // 2

    left = query(tree, 2 * idx + 1, tl, tm, l, r)
    right = query(tree, 2 * idx + 2, tm + 1, tr, l, r)

    if left[0] >= right[0]:
        return left
    elif left[0] < right[0]:
        return right


def build(tree, nums, size):
    for i in range(len(nums)):
        tree[size - 1 + i] = [nums[i], i]

    for i in range(size - 2, -1, -1):
        left = tree[2 * i + 1]
        right = tree[2 * i + 2]

        if left[0] >= right[0]:
            tree[i] = left
        else:
            tree[i] = right


def main():
    n = int(input())
    nums = list(map(int, input().split()))
    
    _pow = 0
    while (1 << _pow) < n:
        _pow += 1
    size = 1 << _pow
    tree = [[0, -1] for _ in range(2 * size - 1)]

    build(tree, nums, size)

    k = int(input())
    for _ in range(k):
        query_l, query_r = map(int, input().split())
        max_value, idx = query(tree, 0, 0, size - 1, query_l - 1, query_r - 1)
        print(idx + 1)


if __name__ == "__main__":
    main()
