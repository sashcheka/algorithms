#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

unordered_map<char, vector<int>> directions = { {'^', {-1, 0}}, {'>', {0, 1}}, {'v', {1, 0}}, {'<', {0, -1}} };

pair<int, int> can_push(int r, int c, char move, const vector<vector<char>>& grid) {
    // cout << "curr pos: " << r << ' ' << c << ' ' << move << '\n';
    int n = grid.size();
    int m = grid[0].size();

    int rd = directions[move][0];
    int cd = directions[move][1];

    int rn = r + rd;
    int cn = c + cd;
    // cout << "next pos: " << rn << ' ' << cn << '\n';
    bool space = false;
    while (rn >= 0 && rn < n && cn >= 0 && cn < m && grid[rn][cn] != '#') {
        if (grid[rn][cn] == '.') {
            space = true;
            break;
        }
        rn += rd;
        cn += cd;
    }
        
    pair<int, int> ans;
    if (space) {
        ans = {rn, cn};
        // cout << "empty space: " << rn << ' ' << cn << '\n';
    } else {
        ans = {-1, -1};
    }

    return ans;
}

int main() {
    ifstream file("input_1.txt");
    string line;

    int i = 0;
    int rs, cs;
    vector<vector<char>> grid;
    while (getline(file, line)) {
        if (line.empty()) break;

        int n = line.size();
        vector<char> row(n);
        for (int j = 0; j < n; j++) {
            row[j] = line[j];
            if (line[j] == '@') {
                rs = i;
                cs = j;
            }
        }
        grid.push_back(row);
        i++;
    }

    int n = grid.size();
    int m = grid[0].size();
    while (getline(file, line)) {
        for (const char move : line) {
            pair<int, int> p = can_push(rs, cs, move, grid);
            if (p.first == -1) continue;

            int rn = p.first;
            int cn = p.second;

            int rd = directions[move][0];
            int cd = directions[move][1];
            int r = rn;
            int c = cn;
            while (r != rs || c != cs) {
                swap(grid[r][c], grid[r - rd][c - cd]);
                r -= rd;
                c -= cd;
            }

            rs += rd;
            cs += cd;
        }
    }

    long long gps = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'O') gps += i * 100 + j;
        }
    }
    cout << gps;
        
    return 0;
}
