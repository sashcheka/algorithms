#include<iostream>
#include<vector>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    long long count = (long long)(n * m) / k;
    long long num = 0;
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                num = num % 2 + 1;
                grid[i][j] = num;
            }
        } else {
            for (int j = 0; j < m; j++) {
                num = num % 2 + 1;
                grid[i][m - j - 1] = num;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " \n"[j == m - 1];
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
