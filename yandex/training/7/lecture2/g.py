def build(tree_pref, tree_suf, tree_max, len_tree, size, nums):
    for i in range(size):
        idx = size - 1 + i
        len_tree[idx] = 1

        if i < len(nums) and nums[i] == 0:
            tree_pref[idx] = 1
            tree_suf[idx] = 1
            tree_max[idx] = 1
        else:
            tree_pref[idx] = 0
            tree_suf[idx] = 0
            tree_max[idx] = 0

    for i in range(size - 2, -1, -1):
        left = 2 * i + 1
        right = 2 * i + 2

        len_tree[i] = len_tree[left] + len_tree[right]
        tree_pref[i] = tree_pref[left] if tree_pref[left] != len_tree[left] else len_tree[left] + tree_pref[right]
        tree_suf[i] = tree_suf[right] if tree_suf[right] != len_tree[right] else len_tree[right] + tree_suf[left]
        tree_max[i] = max(tree_max[left], tree_max[right], tree_suf[left] + tree_pref[right])


def update(tree_pref, tree_suf, tree_max, len_tree, size, pos, value):
    idx = size - 1 + pos

    if value == 0:
        tree_pref[idx] = 1
        tree_suf[idx] = 1
        tree_max[idx] = 1
    else:
        tree_pref[idx] = 0
        tree_suf[idx] = 0
        tree_max[idx] = 0

    while idx > 0:
        idx = (idx - 1) // 2
        left = 2 * idx + 1
        right = 2 * idx + 2

        tree_pref[idx] = tree_pref[left] if tree_pref[left] != len_tree[left] else len_tree[left] + tree_pref[right]
        tree_suf[idx] = tree_suf[right] if tree_suf[right] != len_tree[right] else len_tree[right] + tree_suf[left]
        tree_max[idx] = max(tree_max[left], tree_max[right], tree_suf[left] + tree_pref[right])


def query(tree_pref, tree_suf, tree_max, len_tree, idx, tl, tr, l, r):
    if tr < l or tl > r:
        return (0, 0, 0, 0)  # prefix, sufix, maxi, length

    if l <= tl and tr <= r:
        return (tree_pref[idx], tree_suf[idx], tree_max[idx], len_tree[idx])

    mid = (tl + tr) // 2
    left_res = query(tree_pref, tree_suf, tree_max, len_tree, 2 * idx + 1, tl, mid, l, r)
    right_res = query(tree_pref, tree_suf, tree_max, len_tree, 2 * idx + 2, mid + 1, tr, l, r)
    
    lp, ls, lm, ll = left_res
    rp, rs, rm, rl = right_res
    total_len = ll + rl

    pref = lp if lp != ll else ll + rp
    suf = rs if rs != rl else rl + ls
    maxi = max(lm, rm, ls + rp)

    return (pref, suf, maxi, total_len)


def main():
    n = int(input())
    nums = list(map(int, input().split()))

    p = 0
    while (1 << p) < n:
        p += 1
    size = 1 << p

    N = 2 * size - 1
    tree_pref = [0] * N
    tree_suf = [0] * N
    tree_max = [0] * N
    len_tree = [0] * N

    build(tree_pref, tree_suf, tree_max, len_tree, size, nums)

    m = int(input())
    out = []
    for _ in range(m):
        line = list(input().split())
        if line[0] == 'UPDATE':
            idx = int(line[1]) - 1
            x = int(line[2])
            update(tree_pref, tree_suf, tree_max, len_tree, size, idx, x)
        elif line[0] == "QUERY":
            l = int(line[1]) - 1
            r = int(line[2]) - 1
            _, _, ans, _ = query(tree_pref, tree_suf, tree_max, len_tree, 0, 0, size - 1, l, r)
            out.append(ans)
    
    print(*out, sep='\n')


if __name__ == '__main__':
    main()