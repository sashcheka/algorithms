def get_smallest_bit(smallest_bit_mask):
    return smallest_bit_mask.bit_length() - 1

def main():
    n, k = map(int, input().split())

    XY = [0] * n
    XZ = [0] * n
    YZ = [0] * n
    for _ in range(k):
        x, y, z = map(int, input().split())
        x -= 1
        y -= 1
        z -= 1
        XY[x] |= 1 << y
        XZ[x] |= 1 << z
        YZ[y] |= 1 << z
    full_mask = (1 << n) - 1

    for x in range(n):
        free_y_mask = (~XY[x]) & full_mask

        while free_y_mask:
            smallest_bit_y_mask = free_y_mask & -free_y_mask
            y = get_smallest_bit(smallest_bit_y_mask)

            attacked_z_mask = XZ[x] | YZ[y]
            free_z_mask = (~attacked_z_mask) & full_mask

            if free_z_mask:
                smallest_bit_z_mask = free_z_mask & -free_z_mask
                z = get_smallest_bit(smallest_bit_z_mask)
                print("NO")
                print(x + 1, y + 1, z + 1)
                return

            free_y_mask ^= smallest_bit_y_mask

    print("YES")
    return


if __name__ == "__main__":
    main()