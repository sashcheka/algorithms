import sys
sys.setrecursionlimit(200000)


class SegmentTree:
    def __init__(self, data):
        self.n = len(data)
        self.tree = [None] * (4 * self.n)
        self.build(data, 1, 0, self.n - 1)

    def build(self, data, v, tl, tr):
        if tl == tr:
            self.tree[v] = (data[tl], 1)
        else:
            tm = (tl + tr) // 2
            self.build(data, v * 2, tl, tm)
            self.build(data, v * 2 + 1, tm + 1, tr)
            self.tree[v] = self._merge(self.tree[v * 2], self.tree[v * 2 + 1])

    def _merge(self, a, b):
        if a[0] == b[0]:
            return (a[0], a[1] + b[1])
        elif a[0] > b[0]:
            return a
        else:
            return b

    def query(self, v, tl, tr, l, r):
        if l > r:
            return (-1, 0)
        if l == tl and r == tr:
            return self.tree[v]
        tm = (tl + tr) // 2
        left = self.query(v * 2, tl, tm, l, min(r, tm))
        right = self.query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
        return self._merge(left, right)


def main():
    n = int(input())
    nums = list(map(int, input().split()))
    tree = SegmentTree(nums)

    k = int(input())
    for _ in range(k):
        l, r = map(int, input().split())
        max_val, count = tree.query(1, 0, n - 1, l - 1, r - 1)
        print(max_val, count)


if __name__ == "__main__":
    main()
