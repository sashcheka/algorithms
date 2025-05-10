#include<bits/stdc++.h>

using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;

    vector<pair<int, int>> exits;
    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'E') exits.push_back({i, j});
        }
    }

    vector<tuple<int, int, char>> dirs = {
        {0, 1, '<'}, 
        {0, -1, '>'},
        {1, 0, '^'},
        {-1, 0, 'v'}
    };

    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    for (auto& [i, j] : exits) pq.push({0, i, j}); // dist, row, col

    while (!pq.empty()) {
        vector<int> v = pq.top();
        pq.pop();

        int dist = v[0];
        int i = v[1];
        int j = v[2];

        for (auto& [di, dj, move_dir] : dirs) {
            int ni = i + di;
            int nj = j + dj;

            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (grid[ni][nj] != '.') continue;

            grid[ni][nj] = move_dir;
            pq.push({dist + 1, ni, nj, move_dir});
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}