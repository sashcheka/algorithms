#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_set>

using namespace std;

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int sr, sc;
int er, ec;
    
string serialize_path(const vector<pair<int, int>>& path) {
    stringstream ss;
    for (const auto& [x, y] : path) {
        ss << x << "," << y << ";";
    }
    return ss.str();
}

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

    auto [basic_dist, basic_path] = find_path(grid);

    int res = 0;
    // vector<vector<bool>> visited(n, vector<bool>(m, false));
    // vector<vector<vector<pair<int, int>>>> visited(n, vector<vector<pair<int, int>>>(m));
    unordered_set<string> visited; 

    queue<tuple<int, int, int, int, vector<pair<int, int>>, int>> q; // dist, row, col, cheats, path
    q.push({0, sr, sc, 20, {}, 0});

    while (!q.empty()) {
        auto [dist, row, col, cheats, path, cheat] = q.front();
        q.pop();

        string spath = !!!;
        if (visited.count(spath)) continue;
        visited.insert(spath);

        if (row == er && col == ec) {
            if (basic_dist >= dist) cout << basic_dist - dist << '\n';
            if (basic_dist - dist >= 50) res++;
        }

        for (auto [dr, dc] : directions) {
            int nr = dr + row;
            int nc = dc + col;

            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (grid[nr][nc] == '#' && cheats > 0 && (cheat == 0 || cheat == 1)) {
                    path.push_back({nr, nc});
                    q.push({dist + 1, nr, nc, cheats - 1, path, 1});
                } else if (grid[nr][nc] != '#') {
                    if (cheat == 0) {
                        path.push_back({nr, nc});
                        q.push({dist + 1, nr, nc, cheats, path, 0});
                    } else if (cheat == 1) {
                        path.push_back({nr, nc});
                        q.push({dist + 1, nr, nc, cheats, path, 2});
                    } else if (cheat == 2) {
                        path.push_back({nr, nc});
                        q.push({dist + 1, nr, nc, cheats, path, 2});
                    }
                }
            }
        }
    }
    
    cout << res;
    return 0;
}
