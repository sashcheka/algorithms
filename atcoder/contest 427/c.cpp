#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u - 1, v - 1};
    }

    int full_mask = 1 << n;
    int ans = INT_MAX;
    for (int mask = 0; mask < full_mask; mask++) {
        int del = 0;
        for (auto& [u, v] : edges) {
            int u_color = (mask >> u) & 1;
            int v_color = (mask >> v) & 1;
            if (u_color == v_color) del++;
        }
        ans = min(ans, del);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}