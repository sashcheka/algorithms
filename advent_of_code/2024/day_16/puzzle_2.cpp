#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#include <cmath>
#include <fstream>
#include <sstream>
#include <set>
#include <map>

using namespace std;

vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
    ifstream file("input_1.txt");
    string line;

    int sr, sc;
    int er, ec;

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

    vector<vector<vector<int>>> distance(n, vector<vector<int>>(m, vector<int>(4, INT_MAX)));
    distance[sr][sc][0] = 0;

    priority_queue<tuple<int, int, int, int, vector<pair<int, int>>>, vector<tuple<int, int, int, int, vector<pair<int, int>>>>, greater<>> pq; // dist, row, col, dir_idx
    pq.push({0, sr, sc, 0, {}});

    map<int, set<pair<int, int>>> dupa;

    while (!pq.empty()) {
        auto [dist, row, col, dir_idx, path] = pq.top();
        pq.pop();

        if (row == er && col == ec) {
            for (pair<int, int> p : path) dupa[dist].insert(p);
        }

        if (dist > distance[row][col][dir_idx]) continue;
        distance[row][col][dir_idx] = dist;
        path.push_back({row, col});

        int new_row = row + directions[dir_idx].first;
        int new_col = col + directions[dir_idx].second;
        if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && grid[new_row][new_col] != '#') {
            pq.push({dist + 1, new_row, new_col, dir_idx, path});
        }

        pq.push({dist + 1000, row, col, (dir_idx - 1 + 4) % 4, path});
        pq.push({dist + 1000, row, col, (dir_idx + 1 + 4) % 4, path});
    }

    for (auto [r, c] : dupa.begin()->second) {
        grid[r][c] = ' ';
    }
    grid[er][ec] = ' ';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " \n"[j == m - 1];
        }
    }

    cout << dupa.begin()->second.size() + 1;
    return 0;
}
