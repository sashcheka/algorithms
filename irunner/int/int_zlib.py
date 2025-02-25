#!/usr/bin/env python3
import sys
import zlib

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
    header = bytes([n & 0xFF, (n >> 8) & 0xFF, m & 0xFF, (m >> 8) & 0xFF])
    
    # Read the matrix and build a bytes object.
    matrix_vals = []
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
            matrix_vals.append(val)
    
    raw = header + bytes(matrix_vals)
    # Compress the raw bytes.
    comp = zlib.compress(raw, level=9)
    # Convert compressed bytes to a list of integers.
    out = list(comp)
    k = len(out)
    
    sys.stdout.write(f"{k}\n")
    sys.stdout.write(" ".join(str(x) for x in out))


def decode():
    # Read the total number of compressed bytes (k)
    k_line = sys.stdin.readline().strip()
    if not k_line:
        sys.exit("Missing total bytes line.")
    try:
        k = int(k_line)
    except Exception:
        sys.exit("Error converting total bytes to int.")
    
    # Read the compressed data as space-separated numbers.
    comp_line = sys.stdin.readline().strip()
    comp_nums = list(map(int, comp_line.split()))
    if len(comp_nums) != k:
        sys.exit("Encoded data length does not match k.")
    comp_bytes = bytes(comp_nums)
    
    # Decompress the data.
    raw = zlib.decompress(comp_bytes)
    # The first 4 bytes form the header.
    header = raw[:4]
    n = header[0] + (header[1] << 8)
    m = header[2] + (header[3] << 8)
    matrix_bytes = list(raw[4:])
    if len(matrix_bytes) != n * m:
        sys.exit("Matrix data length does not match expected dimensions.")
    
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
    command = sys.stdin.readline().strip()
    if command == "0":
        encode()
    elif command == "1":
        decode()
    else:
        sys.exit("Invalid command.")

if __name__ == '__main__':
    main()
