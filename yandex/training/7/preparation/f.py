def heapify_up(heap, idx):
    parent = (idx - 1) // 2

    if idx > 0 and heap[idx] > heap[parent]:
        heap[idx], heap[parent] = heap[parent], heap[idx]
        heapify_up(heap, parent)


def heapify_down(heap, idx):
    next_idx = idx
    left = idx * 2 + 1
    right = idx * 2 + 2

    n = len(heap)

    if left < n and heap[left] > heap[next_idx]:
        next_idx = left
    if right < n and heap[right] > heap[next_idx]:
        next_idx = right

    if next_idx != idx:
        heap[idx], heap[next_idx] = heap[next_idx], heap[idx]
        heapify_down(heap, next_idx)


def main():
    n = int(input())
    heap = []

    for i in range(n):
        line = list(map(int, input().split()))
        if line[0] == 0:
            heap.append(line[1])
            idx = len(heap) - 1
            heapify_up(heap, idx)
        else:
            heap[0], heap[-1] = heap[-1], heap[0]
            print(heap.pop())
            idx = 0
            heapify_down(heap, idx)

    

if __name__ == '__main__':
    main()