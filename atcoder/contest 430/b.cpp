#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    set<vector<string>> setik;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<string> cand(m);
            if (i + m > n || j + m > n) continue;
            for (int ci = i; ci < i + m; ci++) {
                for (int cj = j; cj < j + m; cj++) {
                    cand[ci - i] += grid[ci][cj];
                }
            }
            setik.insert(cand);
        }
    }

    cout << setik.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}