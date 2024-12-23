#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int sr, sc;
int er, ec;
    
pair<int, vector<pair<int, int>>> find_path(vector<vector<char>> grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<tuple<int, int, int, vector<pair<int, int>>>> q; // dist, row, col, path
    q.push({0, sr, sc, {}});

    while (!q.empty()) {
        auto [dist, row, col, path] = q.front();
        q.pop();

        if (visited[row][col]) continue;
        visited[row][col] = true;
        if (row == er && col == ec) return {dist, path};

        for (auto [dr, dc] : directions) {
            int nr = dr + row;
            int nc = dc + col;

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#') {
                path.push_back({nr, nc});
                q.push({dist + 1, nr, nc, path});
            }
        }
    }

    return {0, {}};
}

int main() {
    ifstream file("test_1.txt");

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

    auto [dist, path] = find_path(grid);

    int cheat_dist = 0;
    for (auto [r, c] : path) {
        int dr = abs(r - er);
        int dc = abs(c - ec);

        if (dr + dc <= 20) {
            cout << r << ' ' << c << '\n';
            cout << dist - cheat_dist - dr - dc << '\n';
            cout << '\n';
        }

        cheat_dist++;
    }
    
    return 0;
}
