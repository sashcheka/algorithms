#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> degree(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        degree[u]++;
        degree[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int d : degree) {
        if (d != 2) {
            cout << "No";
            return;
        }
    }

    vector<bool> seen(n, false);
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (seen[u]) continue;
        seen[u] = true;

        for (int v : adj[u]) {
            if (!seen[v]) {
                q.push(v);
            }
        }
    }

    for (int s : seen) {
        if (!s) {
            cout << "No";
            return;
        }
    }

    cout << "Yes";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}