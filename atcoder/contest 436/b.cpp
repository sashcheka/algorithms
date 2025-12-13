#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));

    int r = 0;
    int c = (n - 1) / 2;
    grid[r][c] = 1;
    for (int i = 0; i < (n * n - 1); i++) {
        int k = grid[r][c];
        if (grid[(r - 1 + n) % n][(c + 1) % n] == 0) {
            r = (r - 1 + n) % n;
            c = (c + 1) % n;
            grid[r][c] = k + 1;
        } else {
            r = (r + 1) % n;
            grid[r][c] = k + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " \n"[j == n - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}