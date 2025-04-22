def update(tree, idx, new_value):
    if idx == 0:
        return

    parent_idx = (idx - 1) // 2
    tree[parent_idx] = max(tree[2 * parent_idx + 1], tree[2 * parent_idx + 2])

    update(tree, parent_idx, tree[parent_idx])


def query(tree, idx, tl, tr, l, r):
    if l > r:
        return 0

    if l == tl and r == tr:
        return tree[idx]

    tm = tl + (tr - tl) // 2

    left = query(tree, 2 * idx + 1, tl, tm, l, r)
    right = query(tree, 2 * idx + 2, tm + 1, tr, l, r)

    return max(left, right)


def build(tree, nums, size):
    for i in range(len(nums)):
        tree[size - 1 + i] = nums[i]

    for i in range(size - 2, -1, -1):
        left = tree[2 * i + 1]
        right = tree[2 * i + 2]
        tree[i] = max(left, right)


def main():
    n = int(input())
    nums = list(map(int, input().split()))
    
    _pow = 0
    while (1 << _pow) < n:
        _pow += 1
    size = 1 << _pow
    tree = [0] * (2 * size - 1)

    build(tree, nums, size)

    result = []
    k = int(input())
    for _ in range(k):
        oper, a, b = input().split()
        a = int(a)
        b = int(b)
        if oper == 's':
            query_l = a - 1
            query_r = b - 1
            max_value = query(tree, 0, 0, size - 1, query_l, query_r)
            result.append(max_value)
        elif oper == 'u':
            idx = a - 1
            new_value = b
            tree[size - 1 + idx] = new_value
            update(tree, size - 1 + idx, new_value)

    print(*result)
    return


if __name__ == "__main__":
    main()
