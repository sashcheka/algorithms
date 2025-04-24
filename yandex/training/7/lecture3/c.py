def main():
    n = int(input())
    nums = list(map(int, input().split()))

    max_num = max(nums)
    bit = 1
    m = 1
    while max_num:
    	if max_num & 1:
    		m = bit
    	bit += 1
    	max_num >>= 1

    matrix = [[0] * m for _ in range(n)]
    cols_count = [0] * m
    for i in range(n):
        for j in range(m):
            bit_pos = m - 1 - j
            if nums[i] & (1 << bit_pos):
                matrix[i][j] = 1
                cols_count[j] += 1

    bits_to_fix = []  # [count, index]
    zero_bits = []
    for j in range(m):
        if cols_count[j] % 2:
            bits_to_fix.append([cols_count[j], j])
        elif cols_count[j] == 0:
            zero_bits.append([0, j])

    if len(bits_to_fix) % 2:
        print("impossible")
        return

    bits_to_fix.sort(key=lambda x: x[0], reverse=True)

    for i in range(n):
        if not bits_to_fix:
            break

        for j in range(len(bits_to_fix) // 2):
            first = bits_to_fix[j]
            last = bits_to_fix[-1 - j]

            if first[0] == -1 or last[0] == -1:
                continue

            if matrix[i][first[1]] == 1 and matrix[i][last[1]] == 0:
                matrix[i][first[1]] = 0
                matrix[i][last[1]] = 1
                first[0] = -1
                last[0] = -1

    remain_bits = 0
    for v in bits_to_fix:
    	if v[0] != -1:
    		remain_bits += 1
    if remain_bits > 2 * len(zero_bits):
        print("impossible")
        return

    for i in range(n):
        if not remain_bits:
            break

        for j in range(len(bits_to_fix)):
            if bits_to_fix[j][0] == -1:
                continue

            if not zero_bits:
                break

            zero_col = zero_bits[0][1]
            fix_col = bits_to_fix[j][1]
            if matrix[i][zero_col] == 0:
                matrix[i][fix_col] = 0
                matrix[i][zero_col] = 1
                bits_to_fix[j][0] = -1
                zero_bits[0][0] += 1
                remain_bits -= 1
                if zero_bits[0][0] == 2:
                    zero_bits.pop(0)

    result = []
    for i in range(n):
        val = 0
        for j in range(m):
            bit = m - 1 - j
            if matrix[i][j]:
            	val += 1 << bit
        result.append(val)

    print(*result)

if __name__ == "__main__":
    main()
