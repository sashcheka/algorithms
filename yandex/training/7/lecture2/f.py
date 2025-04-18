class SegmentTree:
    def __init__(self, data):
        self.n = len(data)
        self.size = 1
        while self.size < self.n:
            self.size <<= 1
        self.tree = [-1] * (2 * self.size)

        for i in range(self.n):
            self.tree[self.size + i] = data[i]
            
        for i in range(self.size - 1, 0, -1):
            self.tree[i] = max(self.tree[2 * i], self.tree[2 * i + 1])
    
    def update(self, pos, value):
        pos += self.size
        self.tree[pos] = value
        while pos > 1:
            pos >>= 1
            new_val = max(self.tree[2 * pos], self.tree[2 * pos + 1])
            if self.tree[pos] == new_val:
                break
            self.tree[pos] = new_val
    
    def _query(self, v, l, r, target, x):
        if r < target or self.tree[v] < x:
            return -1
        if l == r:
            return l

        mid = (l + r) // 2
        left = self._query(2*v, l, mid, target, x)
        if left != -1:
            return left

        return self._query(2*v+1, mid+1, r, target, x)
    
    def query(self, i, x):
        res = self._query(1, 0, self.size-1, i-1, x)
        return res + 1 if res != -1 else -1


def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    st = SegmentTree(a)
    for _ in range(m):
        t, i, x = map(int, input().split())
        if t == 0:
            pos = i - 1
            st.update(pos, x)
        else:
            print(st.query(i, x))


if __name__ == "__main__":
    main()