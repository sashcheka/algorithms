class SegmentTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [0] * (4 * self.n)
        self.build(arr, 0, 0, self.n - 1)

    def build(self, arr, node, start, end):
        if start == end:
            self.tree[node] = 1 if arr[start] == 0 else 0
        else:
            mid = (start + end) // 2
            left_child = 2 * node + 1
            right_child = 2 * node + 2
            self.build(arr, left_child, start, mid)
            self.build(arr, right_child, mid + 1, end)
            self.tree[node] = self.tree[left_child] + self.tree[right_child]

    def update(self, idx, value, node, start, end):
        if start == end:
            self.tree[node] = 1 if value == 0 else 0
        else:
            mid = (start + end) // 2
            left_child = 2 * node + 1
            right_child = 2 * node + 2
            if start <= idx <= mid:
                self.update(idx, value, left_child, start, mid)
            else:
                self.update(idx, value, right_child, mid + 1, end)
            self.tree[node] = self.tree[left_child] + self.tree[right_child]

    def query(self, l, r, node, start, end):
        if r < start or end < l:
            return 0
        if l <= start and end <= r:
            return self.tree[node]
        mid = (start + end) // 2
        left_child = 2 * node + 1
        right_child = 2 * node + 2
        left_result = self.query(l, r, left_child, start, mid)
        right_result = self.query(l, r, right_child, mid + 1, end)
        return left_result + right_result

    def find_kth_zero(self, l, r, k, node, start, end):
        if end < l or start > r:
            return (0, -1)

        # Current segment is fully within [l, r]
        if l <= start and end <= r:
            total = self.tree[node]
            if total < k:
                return (total, -1)
                
            if start == end:
                return (total, start)

            mid = (start + end) // 2
            left = 2 * node + 1
            left_total = self.tree[left]
            if left_total >= k:
                return self.find_kth_zero(l, r, k, left, start, mid)
            else:
                res = self.find_kth_zero(l, r, k - left_total, left + 1, mid + 1, end)
                return (total, res[1])

        # Partially overlapping: check left and right children
        mid = (start + end) // 2
        left = 2 * node + 1
        right = 2 * node + 2

        # Check left child
        left_count, left_pos = self.find_kth_zero(l, r, k, left, start, mid)
        if left_pos != -1:
            return (left_count, left_pos)

        # Check right child with adjusted k
        res_count, res_pos = self.find_kth_zero(l, r, k - left_count, right, mid + 1, end)
        total_count = left_count + res_count
        return (total_count, res_pos)


def solve():
    # Ввод данных
    n = int(input())
    arr = list(map(int, input().split()))
    m = int(input())
    
    seg_tree = SegmentTree(arr)
    
    result = []
    
    for _ in range(m):
        query = input().split()
        
        if query[0] == 'u':  # Обновление
            idx = int(query[1]) - 1
            value = int(query[2])
            arr[idx] = value
            seg_tree.update(idx, value, 0, 0, n - 1)
        
        elif query[0] == 's':  # Запрос на поиск k-го нуля
            l = int(query[1]) - 1
            r = int(query[2]) - 1
            k = int(query[3])
            _, idx = seg_tree.find_kth_zero(l, r, k, 0, 0, n - 1)
            result.append(idx + 1 if idx != -1 else -1)
    
    print(*result)

solve()