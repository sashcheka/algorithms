#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int sr, sc;
int er, ec;

int get_path_length(int r, int c, vector<vector<char>> grid) {
    if (r != -1 && c != -1) {
        grid[r][c] = 'X';
    }

    int n = grid.size();
    int m = grid[0].size();
    // for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cout << grid[i][j] << " \n"[j == m - 1];

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<tuple<int, int, int>> q; // dist, row, col;
    q.push({0, sr, sc});

    while (!q.empty()) {
        auto [dist, row, col] = q.front();
        q.pop();

        if (visited[row][col]) continue;
        visited[row][col] = true;
        if (row == er && col == ec) return dist;

        for (auto [dr, dc] : directions) {
            int nr = dr + row;
            int nc = dc + col;

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#') {
                q.push({dist + 1, nr, nc});
            }
        }
    }

    return 0;
}

int main() {
    ifstream file("input_1.txt");

    string line;

    int i = 0;
    vector<vector<char>> grid;
    while (getline(file, line)) {
        int n = line.size();
        vector<char> row(n);
        for (int j = 0; j < n; j++) {
            if (line[j] == 'S') {
                sr = i;
                sc = j;
            } else if (line[j] == 'E') {
                er = i;
                ec = j;
            }

            row[j] = line[j];
        }
        grid.push_back(row);
        i++;
    }

    int n = grid.size();
    int m = grid[0].size();

    // for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cout << grid[i][j] << " \n"[j == m - 1];

    int basic_path = get_path_length(-1, -1, grid);
    // cout << "basic: " << basic_path << '\n';

    int cheats = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0 && i < n - 1 && grid[i][j] == '#' && grid[i - 1][j] != '#' && grid[i + 1][j] != '#') {
                int cheat_path = get_path_length(i, j, grid);
                // cout << "cheat_1: " << cheat_path << '\n';
                if (basic_path - cheat_path >= 100) cheats++;
                // cout << basic_path - cheat_path << '\n';
            }

            if (j > 0 && j < m - 1 && grid[i][j] == '#' && grid[i][j - 1] != '#' && grid[i][j + 1] != '#') {
                int cheat_path = get_path_length(i, j, grid);
                // cout << "cheat_2: " << cheat_path << '\n';
                if (basic_path - cheat_path >= 100) cheats++;
                // cout << basic_path - cheat_path << '\n';
            }
        }
    }
        
    cout << cheats;
    return 0;
}
