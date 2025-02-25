import sys

def encode():
    # Read dimensions from the second line.
    dims_line = sys.stdin.readline().strip()  # e.g., "3 3"
    if not dims_line:
        sys.stderr.write("Missing dimensions line.\n")
        return
    try:
        n, m = map(int, dims_line.split())
    except Exception as e:
        sys.stderr.write("Error parsing dimensions.\n")
        return

    # Create header: store n and m in 2 bytes each (little-endian)
    header = [
        n & 0xFF,
        (n >> 8) & 0xFF,
        m & 0xFF,
        (m >> 8) & 0xFF
    ]
    
    # Total bytes = header (4 bytes) + n*m bytes for matrix elements.
    total_bytes = 4 + n * m

    # Write header: first output the total number of bytes, then the header.
    sys.stdout.write(f"{total_bytes}\n")
    sys.stdout.write(" ".join(str(x) for x in header))
    
    # Process the matrix row by row.
    for i in range(n):
        # Read the next row (one line from input).
        row_line = sys.stdin.readline().strip()
        if not row_line:
            sys.stderr.write(f"Missing row {i+1}.\n")
            return
        # Split the row into numbers.
        row_tokens = row_line.split()
        if len(row_tokens) != m:
            sys.stderr.write(f"Row {i+1} does not contain {m} numbers.\n")
            return
        # Process each number in the row.
        for j in range(m):
            try:
                val = int(row_tokens[j])
            except Exception as e:
                sys.stderr.write(f"Error converting value on row {i+1}, column {j+1}.\n")
                return
            # Convert signed int8 to its unsigned representation.
            if val < 0:
                val += 256
            # Print value followed by a space.
            sys.stdout.write(" " + str(val))
    sys.stdout.write("\n")
    sys.stdout.flush()


def decode():
    # Read the total number of bytes (k) from the second line.
    k_line = sys.stdin.readline().strip()
    if not k_line:
        sys.stderr.write("Missing total bytes line.\n")
        return
    try:
        k = int(k_line)
    except Exception as e:
        sys.stderr.write("Error converting total bytes to int.\n")
        return

    # Read the next line containing k space-separated numbers.
    numbers_line = sys.stdin.readline().strip()
    if not numbers_line:
        sys.stderr.write("Missing encoded data line.\n")
        return
    tokens = numbers_line.split()
    if len(tokens) != k:
        sys.stderr.write("Encoded data length does not match k.\n")
        return

    # First 4 numbers form the header.
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

    # Output the dimensions.
    sys.stdout.write(f"{n} {m}\n")
    
    # Process and output each row immediately.
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
            # Convert back to signed int8.
            if b >= 128:
                b -= 256
            row_vals.append(str(b))
        sys.stdout.write(" ".join(row_vals) + "\n")
    sys.stdout.flush()


def main():
    # Read the command (first line)
    command_line = sys.stdin.readline().strip()
    if not command_line:
        sys.stderr.write("No command found.\n")
        return
    command = command_line

    # Based on the command, call encode or decode.
    if command == "0":
        encode()
    elif command == "1":
        decode()
    else:
        sys.stderr.write("Invalid command.\n")


if __name__ == '__main__':
    # Open input from "275.txt" and output to "output.txt".
    try:
        with open("275.txt", "r") as f_in, open("output.txt", "w") as f_out:
            sys.stdin = f_in
            sys.stdout = f_out
            main()
    except FileNotFoundError:
        sys.stderr.write("Error: 275.txt not found.\n")
