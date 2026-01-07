#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> parent(n, -1);
    vector<int> child(n, 0);
    vector<int> depth(n, -1);
    unordered_map<int, int> dupa_depth;
    queue<int> q;
    q.push(0);
    depth[0] = 0;
    int ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        dupa_depth[depth[u]]++;
        ans = max(ans, dupa_depth[depth[u]]);
        for (int v : adj[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            child[u]++;
            q.push(v);
        }
    }
    for (int i = 0; i < n; i++) ans = max(ans, 1 + child[i]);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
