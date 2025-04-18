def build(tree, nums, node, start, end):
    if start == end:
        tree[node] = 1 if nums[start] == 0 else 0
    else:
        mid = (start + end) // 2
        left_child = 2 * node + 1
        right_child = 2 * node + 2
        build(tree, nums, left_child, start, mid)
        build(tree, nums, right_child, mid + 1, end)
        tree[node] = tree[left_child] + tree[right_child]


# def build(tree, nums, size):
#     for i in range(len(nums)):
#         tree[size - 1 + i] = 1 if nums[i] == 0 else 0

#     for i in range(size - 2, -1, -1):
#         tree[i] = tree[2 * i + 1] + tree[2 * i + 2]


def update(tree, idx, value, node, start, end):
    if start == end:
        tree[node] = 1 if value == 0 else 0
    else:
        mid = (start + end) // 2
        left_child = 2 * node + 1
        right_child = 2 * node + 2
        if start <= idx <= mid:
            update(tree, idx, value, left_child, start, mid)
        else:
            update(tree, idx, value, right_child, mid + 1, end)
        tree[node] = tree[left_child] + tree[right_child]


# def update(tree, idx):
#     while idx > 0:
#         idx = (idx - 1) // 2
#         tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2]


def query(tree, l, r, node, start, end):
    if r < start or end < l:
        return 0
    if l <= start and end <= r:
        return tree[node]
    mid = (start + end) // 2
    left_child = 2 * node + 1
    right_child = 2 * node + 2
    left_result = query(tree, l, r, left_child, start, mid)
    right_result = query(tree, l, r, right_child, mid + 1, end)
    return left_result + right_result


def find_kth_zero(tree, l, r, k, node, start, end):
    if r < start or end < l:
        return -1

    if l <= start and end <= r:
        if tree[node] < k:
            return -1
        return _find_kth_zero_in_range(tree, l, r, k, node, start, end)

    mid = (start + end) // 2
    left_child = 2 * node + 1
    right_child = 2 * node + 2

    left_count = query(tree, l, r, left_child, start, mid)

    if left_count >= k:
        return find_kth_zero(tree, l, r, k, left_child, start, mid)
    else:
        return find_kth_zero(tree, l, r, k - left_count, right_child, mid + 1, end)


def _find_kth_zero_in_range(tree, l, r, k, node, start, end):
    if start == end:
        return start

    mid = (start + end) // 2
    left_child = 2 * node + 1
    right_child = 2 * node + 2

    left_count = tree[left_child]

    if left_count >= k:
        return _find_kth_zero_in_range(tree, l, r, k, left_child, start, mid)
    else:
        return _find_kth_zero_in_range(tree, l, r, k - left_count, right_child, mid + 1, end)


def main():
    n = int(input())
    nums = list(map(int, input().split()))
    m = int(input())

    _pow = 0
    while (1 << _pow) < n:
        _pow += 1
    size = 1 << _pow
    tree = [0] * (2 * size - 1)

    build(tree, nums, 0, 0, n - 1)
    # build(tree, nums, size)

    result = []
    for _ in range(m):
        query_line = input().split()

        if query_line[0] == 'u':
            idx = int(query_line[1]) - 1
            value = int(query_line[2])
            nums[idx] = value
            update(tree, idx, value, 0, 0, n - 1)
            # tree[size - 1 + idx] = 1 if value == 0 else 0
            # update(tree, size - 1 + idx)
        elif query_line[0] == 's':
            l = int(query_line[1]) - 1
            r = int(query_line[2]) - 1
            k = int(query_line[3])
            idx = find_kth_zero(tree, l, r, k, 0, 0, n - 1)
            result.append(idx + 1 if idx != -1 else -1)

    print(*result)


if __name__ == "__main__":
    main()