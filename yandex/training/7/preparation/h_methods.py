class Tree:
    def __init__(self, left, right, value):
        self.left = left
        self.right = right
        self.value = value


def add(root, value):
    if value == root.value:
        print("ALREADY")
        return root

    if value < root.value:
        if root.left:
            root.left = add(root.left, value)
        else:
            root.left = Tree(None, None, value)
            print("DONE")
    elif value > root.value:
        if root.right:
            root.right = add(root.right, value)
        else:
            root.right = Tree(None, None, value)
            print("DONE")

    return root


def search(root, value):
    if value == root.value:
        print("YES")
        return

    if value < root.value:
        if root.left:
            search(root.left, value)
        else:
            print("NO")
            return
    elif value > root.value:
        if root.right:
            search(root.right, value)
        else:
            print("NO")

    return


def printtree(root, depth):
    if root.left:
        printtree(root.left, depth + 1)

    print('.' * depth + str(root.value))

    if root.right:
        printtree(root.right, depth + 1)


def main():
    root = None
    while True:
        try:
            line = list(map(str, input().split()))
            if not line:
                break
        except Exception:
            return

        if line[0] == "ADD":
            value = int(line[1])
            if not root:
                root = Tree(None, None, value)
                print("DONE")
            else:
                root = add(root, value)
        elif line[0] == "SEARCH":
            value = int(line[1])
            if not root:
                print("NO")
            else:
                search(root, value)
        elif line[0] == "PRINTTREE":
            printtree(root, 0)


if __name__ == "__main__":
    main()