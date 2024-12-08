#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<unordered_map>

using namespace std;

int main() {
    ifstream file("test_1.txt");
    string line;

    unordered_map<char, vector<pair<int, int>>> dupa;
    vector<vector<char>> grid;
    int i = 0;
    while (getline(file, line)) {
        int m = line.size();

        vector<char> row(m);
        for (int j = 0; j < m; j++) {
            row[j] = line[j];
            if (line[j] != '.') dupa[line[j]].push_back({i, j});
        }
        grid.push_back(row);

        i++;
    }

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<char>> new_grid = grid;

    auto overlap = [&](int r1, int c1) {
        char ch = grid[r1][c1];

        for (auto& [r2, c2] : dupa[ch]) {
            if (r1 == r2 && c1 == c2) continue;

            int dr = r1 - r2;
            int dc = c1 - c2;
            
            int nr1 = r1 + dr;
            int nc1 = c1 + dc;
            while (nr1 >= 0 && nr1 < n && nc1 >= 0 && nc1 < m) {
                new_grid[nr1][nc1] = '#';
                nr1 += dr;
                nc1 += dc;
            }

            int nr2 = r2 - dr;
            int nc2 = c2 - dc;
            while (nr2 >= 0 && nr2 < n && nc2 >= 0 && nc2 < m) {
                new_grid[nr2][nc2] = '#';
                nr2 += dr;
                nc2 += dc;
            }
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '.') {
                overlap(i, j);
            }
        }
    }

    int locations = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (new_grid[i][j] == '#') {
                locations++;
            }
            // cout << new_grid[i][j] << " \n"[j == m - 1];
        }
    }

    cout << locations;
    return 0;
}
