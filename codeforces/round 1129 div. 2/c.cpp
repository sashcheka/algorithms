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

    vector<vector<int>> to(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;

        to[x].push_back(y);
        to[y].push_back(x);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == 1) {
            continue;
        }

        for (int v : to[u]) {
            if (dist[v] != -1) {
                continue;
            }
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    int best = dist[1]; // root
    for (int i = 0; i < m; i++) {
        int v;
        cin >> v;
        best = max(best, dist[v] + 1);
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
