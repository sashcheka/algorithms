def decode(z, hht):
    fix = 0

    k = 0
    while (1 << k) < len(hht):
        k += 1
    ctrl_bits_cnt = [0] * k

    for i in range(1, len(hht)):
        for j in range(k):
            if hht[i] and (i & (1 << j)):
                ctrl_bits_cnt[j] += 1

    for j in range(k):
        if ctrl_bits_cnt[j] % 2 == 0:
            fix |= (1 << j)

    hht[fix] ^= 1

    x = ""
    for i in range(1, len(hht)):
        if (i & (i - 1)) != 0:
            x += str(hht[i])

    return x


def code(x, hht, ctrl_bits_cnt):
    k = len(ctrl_bits_cnt)
    ctrl_bits_cnt = [0] * k
    idx = 0

    for i in range(1, len(hht)):
        if (i & (i - 1)) == 0:
            continue

        hht[i] = int(x[idx])
        idx += 1

    for i in range(1, len(hht)):
        for j in range(k):
            if hht[i] and (i & (1 << j)):
                ctrl_bits_cnt[j] += 1

    for j in range(k):
        if (ctrl_bits_cnt[j] % 2):
            hht[1 << j] = 0  
        else:
            hht[1 << j] = 1

    return "".join(map(str, hht[1:]))


def main():
    launch = int(input())

    if launch == 1:
        x = str(input())
        n = len(x)

        k = 0
        while (1 << k) - k - 1 < n:
            k += 1
        hht = [0] * (n + k + 1)
        ctrl_bits_cnt = [0] * k

        y = code(x, hht, ctrl_bits_cnt)
        print(y)
    elif launch == 2:
        z = input().strip()
        k = 0
        while (1 << k) < len(z) + 1:
            k += 1
        hht = [0] + [int(ch) for ch in z]
        x = decode(z, hht)
        print(x)


if __name__ == "__main__":
    main()