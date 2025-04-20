class SegmentTree:
    def __init__(self, data):
        self.n = len(data)
        self.size = 1
        while self.size < self.n:
            self.size <<= 1
        self.tree = [-1] * (2 * self.size - 1)

        for i in range(self.n):
            self.tree[self.size - 1 + i] = data[i]
            
        for i in range(self.size - 2, -1, -1):
            self.tree[i] = max(self.tree[2 * i + 1], self.tree[2 * i + 2])
    
    def update(self, pos, value):
        pos += self.size - 1
        self.tree[pos] = value
        while pos > 0:
            pos = (pos - 1) // 2
            self.tree[pos] = max(self.tree[2 * pos + 1], self.tree[2 * pos + 2])
    
    def query(self, v, l, r, target, x):
        if r < target or self.tree[v] < x:
            return -1
        if l == r:
            return l

        mid = (l + r) // 2
        left = self.query(2*v + 1, l, mid, target, x)
        if left != -1:
            return left

        return self.query(2*v+2, mid+1, r, target, x)


def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    st = SegmentTree(a)
    for _ in range(m):
        t, i, x = map(int, input().split())
        if t == 0:
            st.update(i - 1, x)
        else:
            res = st.query(0, 0, st.size - 1, i - 1, x)
            print(res + 1 if res != -1 else -1)


if __name__ == "__main__":
    main()