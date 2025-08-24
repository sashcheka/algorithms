#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<char>>& grid, int i, int j, int SWITCH) {
    char c = grid[i][j];
    if (c == '#') return false;
    if (c == 'o') return SWITCH == 0;
    if (c == 'x') return SWITCH == 1;
    return true;
};

void solve() {
    int h, w;
    cin >> h >> w;

    pair<int, int> start;
    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') start = {i, j};
        }
    }

    const int INF = 1e9;
    vector<vector<vector<int>>> dist(h, vector(w, vector<int>(2, INF)));
    dist[start.first][start.second][0] = 0;

    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // DIST, I, J, SWITCH
    pq.push({0, start.first, start.second, 0});
    int DIST = 0;
    int I = 1;
    int J = 2;
    int SWITCH = 3;

    while (!pq.empty()) {
        vector<int> curr = pq.top();
        pq.pop();

        int DIST = curr[0];
        int i = curr[1];
        int j = curr[2];
        int SWITCH = curr[3];

        if (DIST != dist[i][j][SWITCH]) continue;

        if (grid[i][j] == 'G') {
            cout << DIST;
            return;
        }

        for (auto [di, dj] : dirs) {
            int ni = i + di;
            int nj = j + dj;
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (!check(grid, ni, nj, SWITCH)) continue;

            int ns = (SWITCH + (grid[ni][nj] == '?')) % 2;
            int nd = DIST + 1;
            if (nd < dist[ni][nj][ns]) {
                dist[ni][nj][ns] = nd;
                pq.push({nd, ni, nj, ns});
            }
        }
    }

    cout << -1;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}