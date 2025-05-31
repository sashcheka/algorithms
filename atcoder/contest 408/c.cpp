#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> wall(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        wall[l]++;
        wall[r + 1]--;
    }

    int ans = wall[0];
    for (int i = 1; i < n; i++) {
        wall[i] += wall[i - 1];
        ans = min(ans, wall[i]);
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