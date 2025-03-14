from collections import deque, defaultdict


def main():
    n = int(input())
    tree = defaultdict(list)
    children = set()

    for _ in range(n - 1):
        child, parent = input().split()
        tree[parent].append(child)
        children.add(child)

    root = next(iter({parent for parent in tree} - children))

    queue = deque([(root, 0)])
    levels = {}

    while queue:
        parent, lvl = queue.popleft()
        levels[parent] = lvl
        queue.extend((child, lvl + 1) for child in tree[parent])

    for node, lvl in sorted(levels.items()):
        print(node, lvl)


if __name__ == "__main__":
    main()