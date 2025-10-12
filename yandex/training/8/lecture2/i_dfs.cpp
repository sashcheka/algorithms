#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& memo) {
    if (memo[r][c] != -1) return memo[r][c];
    int best = 1;
    for (auto& [dr, dc] : dirs) {
        int nr = r + dr, nc = c + dc;
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if (grid[nr][nc] != grid[r][c] + 1) continue;
        best = max(best, 1 + dfs(nr, nc, grid, memo));
    }
    return memo[r][c] = best;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> memo(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dfs(i, j, grid, memo));
        }
    }

    cout << ans << "\n";
    return 0;
}