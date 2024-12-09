#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<unordered_map>

using namespace std;

int main() {
    ifstream file("input_1.txt");
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

    long long l = 0;
    long long r = blocks.size() - 1;

    while (l < r) {
        while (l < r && blocks[l] != -1) l++;
        while (l < r && blocks[r] == -1) r--;

        swap(blocks[l], blocks[r]);
        l++;
        r--;
    }

    long long checksum = 0;
    for (long long i = 0; i < blocks.size(); i++) {
        if (blocks[i] == -1) break;
        checksum += i * (long long)blocks[i];
    }

    cout << checksum;
    return 0;
}
