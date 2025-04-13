#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int sum = ((1 + 2 * n) * 2 * n) / 2;
    vector<int> perm(2 * n, -1);
    vector<vector<int>> grid(n,  vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            // cout << "value: " << grid[i][j] << " idx:" << i + 1 + j + 1 - 1 << '\n';
            if (perm[i + 1 + j + 1 - 1] == -1) {
                perm[i + 1 + j + 1 - 1] = grid[i][j];
                sum -= grid[i][j];
            }
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        if (perm[i] == -1) {
            perm[i] = sum;
            for (int num : perm) cout << num << ' ';
            cout << '\n';   
            return;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
