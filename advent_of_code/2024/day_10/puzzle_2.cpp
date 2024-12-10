#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>

using namespace std;

vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void bfs(int r, int c, const vector<vector<int>>& grid, int& scores) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    q.push({r, c});

    while (!q.empty()) {
        auto [cr, cc] = q.front();
        q.pop();

        if (grid[cr][cc] == 9) {
            scores++;
            continue;
        }

        for (auto dir : directions) {
            int nr = cr + dir[0];
            int nc = cc + dir[1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == grid[cr][cc] + 1) {
                q.push({nr, nc});
            }
        }
    }
}

int main() {
    ifstream file("test_1.txt");
    string line;
    
    vector<vector<int>> grid;

    while (getline(file, line)) {
        int n = line.size();
        vector<int> row(n);
        for (int i = 0; i < n; i++) row[i] = line[i] - '0';
        grid.push_back(row);
    }

    int n = grid.size();
    int m = grid[0].size();

    int scores = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) bfs(i, j, grid, scores);
        }
    }
        
    cout << scores;
    return 0;
}
