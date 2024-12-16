#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#include <cmath>
#include <fstream>
#include <sstream>

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

    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(4, false)));

    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq; // dist, row, col, dir_idx
    pq.push({0, sr, sc, 0});

    while (!pq.empty()) {
        auto [dist, row, col, dir_idx] = pq.top();
        pq.pop();

        if (row == er && col == ec) {
            cout << dist;
            return 0;
        }

        if (visited[row][col][dir_idx]) continue;
            visited[row][col][dir_idx] = true;

        int new_row = row + directions[dir_idx].first;
        int new_col = col + directions[dir_idx].second;
        if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && grid[new_row][new_col] != '#') {
            pq.push({dist + 1, new_row, new_col, dir_idx});
        }

        pq.push({dist + 1000, row, col, (dir_idx - 1 + 4) % 4});
        pq.push({dist + 1000, row, col, (dir_idx + 1 + 4) % 4});
    }

    return 0;
}
