#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> cnt(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '#') continue;
            int c = 0;
            for (auto [di, dj] : dirs) {
                int ni = i + di;
                int nj = j + dj;
                if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if (grid[ni][nj] == '#') c++;
            }
            cnt[i][j] = c;
        }
    }

    queue<pair<int,int>> q;
    vector<vector<char>> inq(h, vector<char>(w, 0));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '.' && cnt[i][j] == 1) {
                q.push({i, j});
                inq[i][j] = 1;
            }
        }
    }

    while (!q.empty()) {
        int n = q.size();
        
        vector<pair<int, int>> flip;
        flip.reserve(n);

        while (n--) {
            auto [i, j] = q.front(); q.pop();
            inq[i][j] = 0;
            if (grid[i][j] == '.' && cnt[i][j] == 1) {
                flip.push_back({i, j});
                grid[i][j] = '#';
            }
        }

        if (flip.empty()) break;

        for (auto [i, j] : flip) {
            for (auto [di, dj] : dirs) {
                int ni = i + di;
                int nj = j + dj;
                if (ni < 0 || ni >= h || nj < 0 || nj >= w || grid[ni][nj] == '#') continue;
                cnt[ni][nj]++;
                if (cnt[ni][nj] == 1 && !inq[ni][nj]) {
                    q.push({ni, nj});
                    inq[ni][nj] = 1;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '#') ans++;
        }
    }

    cout << ans;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}