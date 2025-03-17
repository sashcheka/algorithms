class Tree:
    def __init__(self, left, right, value):
        self.left = left
        self.right = right
        self.value = value

    def insert(self, value):
        if value == self.value:
            print("ALREADY")
            return self

        node = Tree(None, None, value)

        if value < self.value:
            if self.left is None:
                self.left = node
                print("DONE")
                return self
            else:
                self.left.insert(value)
        
        if value > self.value:
            if self.right is None:
                self.right = node
                print("DONE")
                return self
            else:
                self.right.insert(value)

        return self

    def search(self, value):
        if self.value == value:
            print("YES")
            return

        if value < self.value:
            if self.left is None:
                print("NO")
                return
            else:
                self.left.search(value)

        if value > self.value:
            if self.right is None:
                print("NO")
                return
            else:
                self.right.search(value)

    def printtree(self, depth):
        if self.left is not None:
            self.left.printtree(depth + 1)

        print("." * depth + str(self.value))

        if self.right is not None:
            self.right.printtree(depth + 1)


def main():
    tree = None

    while True:
        try:
            line = list(map(str, input().split()))
            if not line:
                return

            if line[0] == "ADD":
                value = int(line[1])
                if not tree:
                    tree = Tree(None, None, value)
                    print("DONE")
                else:
                    tree.insert(value)
            elif line[0] == "SEARCH":
                value = int(line[1])
                if not tree:
                    print("NO")
                else:
                    tree.search(value)
            elif line[0] == "PRINTTREE":
                tree.printtree(0)
        except EOFError:
            break


if __name__ == "__main__":
    main()