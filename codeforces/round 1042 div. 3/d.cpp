#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; 
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n == 2) {
        cout << 0 << '\n';
        return;
    }

    vector<int> deg(n+1);
    int leaves = 0;
    for (int v = 1; v <= n; v++) {
        deg[v] = (int)g[v].size();
        if (deg[v] == 1) leaves++;
    }

    int best = 0;
    for (int v = 1; v <= n; v++) {
        int leaf_neighbour = 0;
        for (int u : g[v]) if (deg[u] == 1) ++leaf_neighbour;
        best = max(best, leaf_neighbour);
    }

    cout << (leaves - best) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; 
    cin >> t;
    while (t--) solve();
    return 0;
}
