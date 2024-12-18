#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int main() {
    ifstream file("input_1.txt");

    int n = 71;
    vector<vector<char>> grid(n, vector<char>(n, '.'));

    string line;
    int bytes = 3450;
    for (int i = 0; i < bytes; i++) {
        file >> line;
        int comma = line.find(',');

        int x = stoi(line.substr(0, comma));
        int y = stoi(line.substr(comma + 1));

        cout << "BYTE: " << i << "; " << x << ' ' << y << '\n';
        
        grid[y][x] = '#';
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j] << " \n"[j == n - 1];
            }
        }

        bool reachable = false;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; // dist, row, col
        pq.push({0, 0, 0});

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        while (!pq.empty()) {
            auto [dist, row, col] = pq.top();
            pq.pop();

            if (visited[row][col]) continue;
            visited[row][col] = true;

            if (row == n - 1 && col == n - 1) {
                reachable = true;
                break;
            }

            for (auto [drow, dcol] : dirs) {
                int nrow = row + drow;
                int ncol = col + dcol;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] != '#') {
                    pq.push({dist + 1, nrow, ncol});
                }
            }
        }

        if (!reachable) {
            cout << x << ',' << y;
            return 0;
        }
    }

    return 0;
}
