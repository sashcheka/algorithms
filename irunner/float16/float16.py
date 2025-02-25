#!/usr/bin/env python3
import sys
import struct

def encode():
    # Read dimensions line (e.g., "3 3")
    dims_line = sys.stdin.readline().strip()
    if not dims_line:
        sys.exit("Missing dimensions line.")
    try:
        n, m = map(int, dims_line.split())
    except Exception:
        sys.exit("Error parsing dimensions.")
    
    # Pack n and m as two 2-byte little-endian unsigned integers.
    header = struct.pack("<HH", n, m)
    total_bytes = 4 + 2 * n * m  # 4 bytes header + 2 bytes per element

    # Prepare a list to collect all output byte values.
    out_numbers = list(header)
    
    # Read each of the n matrix rows.
    for i in range(n):
        row_line = sys.stdin.readline().strip()
        if not row_line:
            sys.exit(f"Missing row {i+1}.")
        tokens = row_line.split()
        if len(tokens) != m:
            sys.exit(f"Row {i+1} does not contain {m} numbers.")
        for token in tokens:
            try:
                value = float(token)
            except Exception:
                sys.exit("Error converting matrix value to float.")
            # Pack the float into 2 bytes as float16 (little-endian)
            b = struct.pack("<e", value)
            # Extend our list with the two byte values (each as an integer 0..255)
            out_numbers.extend(b)
    
    # Output exactly two lines:
    # Line 1: total byte count
    # Line 2: the total_bytes integers (each 0..255) space-separated.
    sys.stdout.write(f"{total_bytes}\n")
    sys.stdout.write(" ".join(str(x) for x in out_numbers))
    sys.stdout.flush()


def decode():
    # Read the line containing the total number of bytes.
    k_line = sys.stdin.readline().strip()
    if not k_line:
        sys.exit("Missing total bytes line.")
    try:
        k = int(k_line)
    except Exception:
        sys.exit("Error converting total bytes to int.")
    
    # Read the next line that should contain k space-separated integers.
    data_line = sys.stdin.readline().strip()
    if not data_line:
        sys.exit("Missing encoded data line.")
    tokens = data_line.split()
    if len(tokens) != k:
        sys.exit("Encoded data length does not match k.")
    try:
        byte_list = [int(x) for x in tokens]
    except Exception:
        sys.exit("Error converting encoded tokens to integers.")
    data_bytes = bytes(byte_list)
    
    # Ensure we have at least 4 bytes for the header.
    if len(data_bytes) < 4:
        sys.exit("Not enough data for header.")
    n, m = struct.unpack("<HH", data_bytes[:4])
    expected = 2 * n * m
    matrix_bytes = data_bytes[4:]
    if len(matrix_bytes) != expected:
        sys.exit("Matrix data length does not match expected dimensions.")
    
    # Write the dimensions.
    sys.stdout.write(f"{n} {m}\n")
    offset = 0
    # Process and output each row.
    for i in range(n):
        row_vals = []
        for j in range(m):
            bpair = matrix_bytes[offset:offset+2]
            offset += 2
            value = struct.unpack("<e", bpair)[0]
            row_vals.append(str(value))
        sys.stdout.write(" ".join(row_vals) + "\n")
    sys.stdout.flush()


def main():
    # Read the first line: the command ("0" for encode, "1" for decode)
    command = sys.stdin.readline().strip()
    if command == "0":
        encode()
    elif command == "1":
        decode()
    else:
        sys.exit("Invalid command.")

if __name__ == '__main__':
    main()
