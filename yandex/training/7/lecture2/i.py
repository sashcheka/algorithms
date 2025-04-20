class SegTree:
    def __init__(self, data):
        self.n = len(data)

        self.size = 1
        while self.size < self.n:
            self.size <<= 1

        self.tree = [0] * (2*self.size - 1)
        self.lazy = [0] * (2*self.size - 1)

        for i, v in enumerate(data):
            self.tree[self.size-1 + i] = v

        for v in range(self.size-2, -1, -1):
            self.tree[v] = max(self.tree[2*v+1], self.tree[2*v+2])

    def update(self, v, tl, tr, l, r, add):
        if l > r:
            return

        if l <= tl and tr <= r:
            self.tree[v]  += add
            self.lazy[v] += add
            return

        if self.lazy[v] != 0:
            temp = self.lazy[v]
            left = 2*v + 1
            right = 2*v + 2
            self.tree[left] += temp
            self.lazy[left] += temp
            self.tree[right] += temp
            self.lazy[right] += temp
            self.lazy[v] = 0

        tm = (tl + tr) // 2
        self.update(2*v + 1, tl, tm, l, min(r, tm), add)
        self.update(2*v + 2, tm+1, tr, max(l, tm+1), r, add)

        self.tree[v] = max(self.tree[2*v+1], self.tree[2*v+2])

    def query(self, v, tl, tr, l, r):
        if l > r:
            return -1

        if l <= tl and tr <= r:
            return self.tree[v]

        if self.lazy[v] != 0:
            add = self.lazy[v]
            left = 2*v + 1
            right = 2*v + 2
            self.tree[left] += add
            self.lazy[left] += add
            self.tree[right] += add
            self.lazy[right] += add
            self.lazy[v] = 0

        tm = (tl + tr) // 2

        left = -1
        if l <= tm:
            left  = self.query(2*v+1,   tl,   tm,   l, min(r, tm))

        right = -1
        if r > tm:
            right = self.query(2*v+2, tm+1,   tr, max(l, tm+1), r)
        
        return max(left, right)


def main():
    n = int(input())
    a = list(map(int, input().split()))
    st = SegTree(a)

    m = int(input())
    out = []
    for _ in range(m):
        q = input().split()
        if q[0] == 'a':
            l, r, add = map(int, q[1:])
            st.update(0, 0, st.size - 1, l - 1, r - 1, add)
        elif q[0] == 'm':
            l, r = map(int, q[1:])
            out.append(str(st.query(0, 0, st.size - 1, l - 1, r - 1)))

    print(*out)


if __name__ == "__main__":
    main()
