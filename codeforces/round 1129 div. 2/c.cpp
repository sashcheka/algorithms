#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <climits>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }

    vector<int> depth(n + 1, -1);
    vector<int> branch(n + 1);
    queue<int> q;
    q.push(1);
    depth[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (depth[v] != -1) {
                continue;
            }

            depth[v] = depth[u] + 1;
            branch[v] = (u == 1 ? v : branch[u]);

            q.push(v);
        }
    }

    vector<int> dist(n + 1, -1);
    q.push(n);
    dist[n] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] != -1) {
                continue;
            }

            dist[v] = dist[u] + 1;

            q.push(v);
        }
    }

    int best = depth[n];

    for (int x : v) {
        if (branch[x] == branch[n]) {
            int cand = 1 + dist[x];
            best = max(best, cand);
        }
    }

    cout << best << "\n";

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
