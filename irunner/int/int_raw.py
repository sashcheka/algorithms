#!/usr/bin/env python3
import sys

def encode():
    # Read dimensions from the second line.
    dims_line = sys.stdin.readline().strip()  # e.g., "3 3"
    if not dims_line:
        sys.exit("Missing dimensions line.")
    try:
        n, m = map(int, dims_line.split())
    except Exception:
        sys.exit("Error parsing dimensions.")
    
    # Create header: n and m as 2 bytes each (little-endian)
    header = [n & 0xFF, (n >> 8) & 0xFF, m & 0xFF, (m >> 8) & 0xFF]
    
    # Read the matrix row by row and convert each int8 value to unsigned byte.
    matrix_bytes = []
    for i in range(n):
        row_line = sys.stdin.readline().strip()
        if not row_line:
            sys.exit(f"Missing row {i+1}.")
        row_tokens = row_line.split()
        if len(row_tokens) != m:
            sys.exit(f"Row {i+1} does not contain {m} numbers.")
        for token in row_tokens:
            try:
                val = int(token)
            except Exception:
                sys.exit("Error converting matrix value.")
            if val < 0:
                val += 256
            matrix_bytes.append(val)
    
    compressed = header + matrix_bytes
    k = len(compressed)
    
    # Output: first line is k, second line is the sequence of k numbers.
    sys.stdout.write(f"{k}\n")
    sys.stdout.write(" ".join(map(str, compressed)))

    
def decode():
    # Read the total number of bytes (k)
    k_line = sys.stdin.readline().strip()
    if not k_line:
        sys.exit("Missing total bytes line.")
    try:
        k = int(k_line)
    except Exception:
        sys.exit("Error converting total bytes to int.")
    
    # Read the sequence of k numbers.
    data_line = sys.stdin.readline().strip()
    nums = list(map(int, data_line.split()))
    if len(nums) != k:
        sys.exit("Encoded data length does not match k.")
    
    # Extract header.
    header = nums[:4]
    n = header[0] + (header[1] << 8)
    m = header[2] + (header[3] << 8)
    matrix_bytes = nums[4:]
    if len(matrix_bytes) != n * m:
        sys.exit("Matrix data length does not match expected dimensions.")
    
    # Reconstruct and output the matrix.
    sys.stdout.write(f"{n} {m}\n")
    idx = 0
    for i in range(n):
        row = []
        for j in range(m):
            b = matrix_bytes[idx]
            idx += 1
            if b >= 128:
                b -= 256
            row.append(str(b))
        sys.stdout.write(" ".join(row) + "\n")


def main():
    # The first line is the command.
    command = sys.stdin.readline().strip()
    if command == "0":
        encode()
    elif command == "1":
        decode()
    else:
        sys.exit("Invalid command.")

if __name__ == '__main__':
    main()
