def main():
    n = int(input())

    zero = 1
    one = 1
    two = 0

    for i in range(1, n):
        prev_zero = zero
        zero = zero + one + two
        two = one
        one = prev_zero

    print(zero + one + two)


if __name__ == '__main__':
    main()