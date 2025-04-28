SIZE = 128


def update(fenwick, x, y, z, diff):
    n = len(fenwick)
    i = x
    while i < n:
        j = y
        while j < n:
            k = z
            while k < n:
                fenwick[i][j][k] += diff
                k = k | (k + 1)
            j = j | (j + 1)
        i = i | (i + 1)


def query(fenwick, x, y, z):
    prefix_3d_sum = 0
    i = x
    while i >= 0:
        j = y
        while j >= 0:
            k = z
            while k >= 0:
                prefix_3d_sum += fenwick[i][j][k]
                k = (k & (k + 1)) - 1
            j = (j & (j + 1)) - 1
        i = (i & (i + 1)) - 1
    return prefix_3d_sum


def calculate(fenwick, x1, y1, z1, x2, y2, z2):
    xyz = query(fenwick, x2, y2, z2) - query(fenwick, x1 - 1, y1 - 1, z1 - 1)
    x   = query(fenwick, x1 - 1, y1 - 1, z2 ) - query(fenwick, x1 - 1, y2, z2 )
    y   = query(fenwick, x1 - 1, y2, z1 - 1) - query(fenwick, x2, y1 - 1, z2 )
    z   = query(fenwick, x2, y1 - 1, z1 - 1) - query(fenwick, x2, y2, z1 - 1)
    return xyz + x + y + z


def main():
    n = int(input())
    fenwick = [[[0] * n for _ in range(n)] for _ in range(n)]

    while True:
        line = list(map(int, input().split()))
        cmd = line[0]

        if cmd == 1:
            x, y, z, k = line[1:]
            update(fenwick, x, y, z, k)

        elif cmd == 2:
            x1, y1, z1, x2, y2, z2 = line[1:]
            result = calculate(fenwick, x1, y1, z1, x2, y2, z2)
            print(result)

        elif cmd == 3:
            break

    return


if __name__ == "__main__":
    main()
