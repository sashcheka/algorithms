#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                // right
                if (j + 1 < m && grid[i][j + 1] == '.') ans++;
                // down
                if (i + 1 < n && grid[i + 1][j] == '.') ans++;
            }
        }
    }

    cout << ans;
    return 0;
}