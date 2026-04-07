#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        grid[i] = row;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool no_up = (i == 0 || grid[i - 1][j] != '#' ? true : false);
            bool no_left = (j == 0 || grid[i][j - 1] != '#' ? true : false);
            if (no_up && no_left && grid[i][j] == '#') ans++;
        }
    }

    cout << ans;
    return 0;
}