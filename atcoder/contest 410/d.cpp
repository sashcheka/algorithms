#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 10;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].push_back({b, w});
    }

    vector<vector<bool>> seen(n, vector<bool>(MAX, false));
    queue<pair<int, int>> q;

    seen[0][0] = 1;
    q.push({0, 0});

    while (!q.empty()) {
        auto [u, x] = q.front();
        q.pop();

        for (auto [v, w] : adj[u]) {
            int nx = x ^ w;
            if (!seen[v][nx]) {
                seen[v][nx] = true;
                q.push({v, nx});
            }
        }
    }

    int answer = -1;
    for (int x = 0; x < MAX; x++) {
        if (seen[n -1][x]) {
            answer = x;
            break;
        }
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
