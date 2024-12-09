#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<unordered_map>

using namespace std;

int main() {
    ifstream file("test_1.txt");
    string disk_map;
    
    file >> disk_map;

    vector<int> blocks;
    for (int i = 0; i < disk_map.size(); i++) {
        char ch = disk_map[i];
        if (i % 2 == 0) {
            int id = i / 2;
            int m = ch - '0';
            for (int j = 0; j < m; j++) {
                blocks.push_back(id);
            }
        } else {
            int m = ch - '0';
            for (int j = 0; j < m; j++) {
                blocks.push_back(-1);
            }
        }
    }

    int r = blocks.size() - 1;
    while (r >= 0) {
        int l = 0;
        while (l < r && blocks[l] != -1) l++;
        while (l < r && blocks[r] == -1) r--;

        int spaces = 0;
        int prev_l = l;
        while (l < r && blocks[l] == -1) {
            spaces++;
            l++;
        }

        int cands = 1;
        int prev_r = r;
        while (l < r && r - 1 >= 0 && blocks[r - 1] == blocks[r]) {
            cands++;
            r--;
        }
        r--;

        if (spaces >= cands) {
            for (int i = 0; i < cands; i++) {
                swap(blocks[prev_l], blocks[prev_r]);
                prev_l++;
                prev_r--;
            }
        }
    }

    for (long long i = 0; i < blocks.size(); i++) {
        cout << blocks[i] << " \n"[i == blocks.size() - 1];
    }

    long long checksum = 0;
    for (long long i = 0; i < blocks.size(); i++) {
        if (blocks[i] == -1) continue;
        checksum += i * (long long)blocks[i];
    }

    cout << checksum;
    return 0;
}
