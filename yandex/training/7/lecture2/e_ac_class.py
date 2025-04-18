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
        if r < start or end < l:
            return -1
        if l <= start and end <= r:
            if self.tree[node] < k:
                return -1  # Not enough zeros in the range
            return self._find_kth_zero_in_range(l, r, k, node, start, end)
        
        mid = (start + end) // 2
        left_child = 2 * node + 1
        right_child = 2 * node + 2
        
        left_count = self.query(l, r, left_child, start, mid)
        
        if left_count >= k:
            return self.find_kth_zero(l, r, k, left_child, start, mid)
        else:
            return self.find_kth_zero(l, r, k - left_count, right_child, mid + 1, end)

    def _find_kth_zero_in_range(self, l, r, k, node, start, end):
        # We need to perform a binary search to find the k-th zero in this range
        # We are guaranteed that there are enough zeros in this range.
        
        # Start from the root and narrow down using binary search within the segment.
        if start == end:
            return start  # This is the position of the k-th zero
        
        mid = (start + end) // 2
        left_child = 2 * node + 1
        right_child = 2 * node + 2
        
        # Count of zeros in the left child
        left_count = self.tree[left_child]
        
        if left_count >= k:
            # If there are enough zeros in the left child, search in the left child
            return self._find_kth_zero_in_range(l, r, k, left_child, start, mid)
        else:
            # Otherwise, search in the right child, adjusting k to find the (k-left_count)-th zero
            return self._find_kth_zero_in_range(l, r, k - left_count, right_child, mid + 1, end)


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
            idx = seg_tree.find_kth_zero(l, r, k, 0, 0, n - 1)
            result.append(idx + 1 if idx != -1 else -1)
    
    print(*result)

solve()