#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct FileInfo {
    int start;
    int length;
    bool moved = false;
};

int main() {
    ifstream file("input_1.txt");
    string disk_map;
    file >> disk_map;

    // Parse the disk map
    // Even positions (0,2,4...) represent file lengths
    // Odd positions (1,3,5...) represent free lengths
    // ID increments for each file encountered
    vector<long long> blocks; // store file IDs and -1 for free
    vector<FileInfo> files;
    {
        int file_id = 0;
        int pos = 0;
        for (size_t i = 0; i < disk_map.size(); i += 2) {
            int file_len = disk_map[i] - '0';
            int free_len = 0;
            if (i + 1 < disk_map.size()) {
                free_len = disk_map[i + 1] - '0';
            }

            // File segment
            if (file_len > 0) {
                FileInfo info;
                info.start = pos;
                info.length = file_len;
                files.push_back(info);

                for (int j = 0; j < file_len; j++) {
                    blocks.push_back(file_id);
                    pos++;
                }
                file_id++;
            }

            // Free segment
            for (int j = 0; j < free_len; j++) {
                blocks.push_back(-1);
                pos++;
            }
        }
    }

    // We now have all files and their positions in `files`.
    // Move files in decreasing order of ID:
    for (int fid = (int)files.size() - 1; fid >= 0; fid--) {
        int fstart = files[fid].start;
        int flen = files[fid].length;

        // We want to find a contiguous block of free space to the left of fstart that can hold flen blocks.
        // Start searching from the left towards fstart - 1:
        int best_start = -1;
        int free_count = 0;
        int segment_start = -1;

        for (int i = 0; i < fstart; i++) {
            if (blocks[i] == -1) {
                // If we find free space, start counting if we weren't already
                if (free_count == 0) {
                    segment_start = i;
                }
                free_count++;
                // If we found a segment large enough
                if (free_count >= flen) {
                    // This is a suitable segment
                    best_start = segment_start;
                    break; // We want the leftmost suitable span, so stop at the first found
                }
            } else {
                // Not free, reset count
                free_count = 0;
            }
        }

        // If we found a suitable space, move the file there
        if (best_start != -1) {
            // Clear old position
            for (int i = fstart; i < fstart + flen; i++) {
                blocks[i] = -1;
            }
            // Place the file in the new position
            for (int i = best_start; i < best_start + flen; i++) {
                blocks[i] = fid;
            }
            // Update file start
            files[fid].start = best_start;
        }
    }

    // Compute checksum
    long long checksum = 0;
    for (long long i = 0; i < (long long)blocks.size(); i++) {
        if (blocks[i] != -1) {
            checksum += i * blocks[i];
        }
    }

    cout << checksum << "\n";
    return 0;
}
