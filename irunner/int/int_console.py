import sys


def encode():
    dims_line = sys.stdin.readline().strip()
    if not dims_line:
        sys.stderr.write("Missing dimensions line.\n")
        return
    try:
        n, m = map(int, dims_line.split())
    except Exception as e:
        sys.stderr.write("Error parsing dimensions.\n")
        return

    header = [
        n & 0xFF,
        (n >> 8) & 0xFF,
        m & 0xFF,
        (m >> 8) & 0xFF
    ]

    total_bytes = 4 + n * m

    sys.stdout.write(f"{total_bytes}\n")
    sys.stdout.write(" ".join(str(x) for x in header))
    
    for i in range(n):
        row_line = sys.stdin.readline().strip()
        if not row_line:
            sys.stderr.write(f"Missing row {i+1}.\n")
            return
        row_tokens = row_line.split()
        if len(row_tokens) != m:
            sys.stderr.write(f"Row {i+1} does not contain {m} numbers.\n")
            return
        for j in range(m):
            try:
                val = int(row_tokens[j])
            except Exception as e:
                sys.stderr.write(f"Error converting value on row {i+1}, column {j+1}.\n")
                return
            if val < 0:
                val += 256
            sys.stdout.write(" " + str(val))
    sys.stdout.write("\n")
    sys.stdout.flush()


def decode():
    k_line = sys.stdin.readline().strip()
    if not k_line:
        sys.stderr.write("Missing total bytes line.\n")
        return
    try:
        k = int(k_line)
    except Exception as e:
        sys.stderr.write("Error converting total bytes to int.\n")
        return

    numbers_line = sys.stdin.readline().strip()
    if not numbers_line:
        sys.stderr.write("Missing encoded data line.\n")
        return
    tokens = numbers_line.split()
    if len(tokens) != k:
        sys.stderr.write("Encoded data length does not match k.\n")
        return

    try:
        header = list(map(int, tokens[:4]))
    except Exception as e:
        sys.stderr.write("Error converting header numbers.\n")
        return

    n = header[0] + (header[1] << 8)
    m = header[2] + (header[3] << 8)
    expected = n * m
    if len(tokens[4:]) != expected:
        sys.stderr.write("Matrix data length does not match expected dimensions.\n")
        return

    sys.stdout.write(f"{n} {m}\n")
    
    idx = 4
    for i in range(n):
        row_vals = []
        for j in range(m):
            try:
                b = int(tokens[idx])
            except Exception as e:
                sys.stderr.write(f"Error converting encoded value at index {idx}.\n")
                return
            idx += 1
            if b >= 128:
                b -= 256
            row_vals.append(str(b))
        sys.stdout.write(" ".join(row_vals) + "\n")
    sys.stdout.flush()


def main():
    command_line = sys.stdin.readline().strip()
    if not command_line:
        sys.stderr.write("No command found.\n")
        return
    command = command_line

    if command == "0":
        encode()
    elif command == "1":
        decode()


if __name__ == '__main__':
    main()
