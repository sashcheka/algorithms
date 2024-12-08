#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int main() {
    ifstream file("input_1.txt");
    string line;

    vector<vector<char>> grid;
    int rs, cs;
    int row_idx = 0;
    int init_dir;

    while (getline(file, line)) {
        vector<char> row;
        for (int col_idx = 0; col_idx < line.size(); col_idx++) {
            char ch = line[col_idx];
            if (ch == '^' || ch == '>' || ch == 'v' || ch == '<') {
                rs = row_idx;
                cs = col_idx;

                if (ch == '^') init_dir = 0;
                else if (ch == '>') init_dir = 1;
                else if (ch == 'v') init_dir = 2;
                else if (ch == '<') init_dir = 3;

                ch = '.';
            }
            row.push_back(ch); 
        }
        grid.push_back(row);
        row_idx++;
    }

    int dist = 0;
    int n = grid.size();
    int m = grid[0].size();

    while (rs >= 0 && rs < n && cs >= 0 && cs < m) {
        if (grid[rs][cs] == '.') {
            dist += 1;
            grid[rs][cs] = 'X';
        }

        int dr = rs + directions[init_dir][0];
        int dc = cs + directions[init_dir][1];

        if (dr < 0 || dr >= n || dc < 0 || dc >= m) break;

        if (grid[dr][dc] != '#') {
            rs = dr;
            cs = dc;
        } else {
            init_dir = (init_dir + 1) % 4;
        }
    }
    
    cout << dist;
    return 0;
}
