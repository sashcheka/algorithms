#include <bits/stdc++.h>
using namespace std;

int _find(vector<pair<int, int>>& parent, int v) {
    int root = v;
    while (parent[root].first != root) root = parent[root].first;
    while (parent[v].first != root) {
        int next = parent[v].first;
        parent[v].first = root;
        v = next;
    }
    return root;
}

void _union(vector<pair<int, int>>& parent, int u, int v) {
    u = _find(parent, u);
    v = _find(parent, v);
    if (u == v) return;
    parent[v].first = u;
    parent[u].second += parent[v].second;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<bool> color(n, 0);
    vector<pair<int, int>> parent(n); // parent, black_count
    for (int i = 0; i < n; i++) parent[i] = {i, 0};

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            _union(parent, u, v);
        } else if (type == 2) {
            int v;
            cin >> v;
            v--;
            if (color[v] == 0) {
                color[v] = 1;
                parent[_find(parent, v)].second++;
            } else {
                color[v] = 0;
                parent[_find(parent, v)].second--;
            }
        } else if (type == 3) {
            int v;
            cin >> v;
            v--;
            if (parent[_find(parent, v)].second == 0) {
                cout << "No" << '\n';
            } else {
                cout << "Yes" << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}