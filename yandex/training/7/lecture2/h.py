class SegTree:
    def __init__(self, data):
        self.n = len(data)

        self.size = 1
        while self.size < self.n:
            self.size <<= 1

        self.init = [0] * (2 * self.size - 1)
        for i, v in enumerate(data):
            self.init[self.size - 1 + i] = v

        self.lazy = [0] * (2 * self.size - 1)

    def update(self, v, tl, tr, l, r, add):
        if l > r:
            return

        if l <= tl and tr <= r:
            self.lazy[v] += add
            return

        self.lazy[2*v + 1] += self.lazy[v]
        self.lazy[2*v + 2] += self.lazy[v]
        self.lazy[v] = 0

        tm = (tl + tr) // 2
        if l <= tm:
            self.update(2*v + 1, tl, tm, l, min(r, tm), add)
        if r > tm:
            self.update(2*v + 2, tm+1, tr, max(l, tm+1), r, add)

    def get(self, v, tl, tr, pos):
        if tl == tr:
            return self.init[v] + self.lazy[v]

        self.lazy[2*v + 1] += self.lazy[v]
        self.lazy[2*v + 2] += self.lazy[v]
        self.lazy[v] = 0

        tm = (tl + tr) // 2
        if pos <= tm:
            return self.get(2*v + 1, tl, tm, pos)
        else:
            return self.get(2*v + 2, tm+1, tr, pos)


def main():
    n = int(input())
    a = list(map(int, input().split()))
    st = SegTree(a)

    m = int(input())
    out = []
    for _ in range(m):
        q = input().split()
        if q[0] == 'a':
            l, r, value = int(q[1]), int(q[2]), int(q[3])
            st.update(0, 0, st.size - 1, l - 1, r - 1, value)
        elif q[0] == 'g':
            i = int(q[1])
            value = st.get(0, 0, st.size - 1, i - 1)
            out.append(value)

    print(*out)


if __name__ == "__main__":
    main()