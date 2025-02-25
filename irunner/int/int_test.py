import sys
import struct

def encode(matrix, n, m):
    """Compress the matrix using a simple run-length encoding (RLE) approach."""
    flat_data = [num + 128 for row in matrix for num in row]  # Shift to 0-255
    compressed = []
    
    i = 0
    while i < len(flat_data):
        count = 1
        while i + count < len(flat_data) and flat_data[i] == flat_data[i + count] and count < 255:
            count += 1
        
        compressed.append(flat_data[i])
        compressed.append(count)
        i += count
    
    return compressed

def decode(byte_sequence):
    """Decompress the byte sequence back into the original matrix."""
    decompressed = []
    i = 0
    while i < len(byte_sequence):
        value = byte_sequence[i] - 128  # Reverse shift
        count = byte_sequence[i + 1]
        decompressed.extend([value] * count)
        i += 2
    
    return decompressed

def main():
    input_data = sys.stdin.read().split()
    command = int(input_data[0])
    
    if command == 0:
        n, m = map(int, input_data[1:3])
        matrix = [list(map(int, input_data[3 + i * m:3 + (i + 1) * m])) for i in range(n)]
        compressed = encode(matrix, n, m)
        print(len(compressed))
        print(" ".join(map(str, compressed)))
    
    elif command == 1:
        k = int(input_data[1])
        byte_sequence = list(map(int, input_data[2:]))
        decompressed = decode(byte_sequence)
        
        n, m = -1, -1
        for i in range(1, int(len(decompressed) ** 0.5) + 1):
            if len(decompressed) % i == 0:
                n, m = i, len(decompressed) // i
                break
        
        print(n, m)
        for i in range(n):
            print(" ".join(map(str, decompressed[i * m:(i + 1) * m])))

if __name__ == "__main__":
    main()
