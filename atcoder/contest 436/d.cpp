#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

void solve() {
    int h, w;
    cin >> h >> w;

    vector<string> maze(h);
    for (int i = 0; i < h; i++) cin >> maze[i];

    vector<vector<pair<int,int>>> warp(26);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if ('a' <= maze[i][j] && maze[i][j] <= 'z') {
                int id = maze[i][j] - 'a';
                warp[id].push_back({i, j});
            }
        }
    }

    vector<vector<int>> dist(h, vector<int>(w, INF));
    queue<pair<int,int>> q;

    dist[0][0] = 0;
    q.push({0, 0});

    vector<bool> used_warps(26, false);

    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        int d = dist[r][c];
        for (auto [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            if (maze[nr][nc] == '#') continue;
            if (dist[nr][nc] > d + 1) {
                dist[nr][nc] = d + 1;
                q.push({nr, nc});
            }
        }

        char ch = maze[r][c];
        if ('a' <= ch && ch <= 'z') {
            int id = ch - 'a';
            if (!used_warps[id]) {
                used_warps[id] = true;
                for (auto [nr, nc] : warp[id]) {
                    if (dist[nr][nc] > d + 1) {
                        dist[nr][nc] = d + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

    int ans = dist[h - 1][w - 1];
    cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}