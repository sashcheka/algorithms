#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    queue<int> q;
    q.push(1);

    unordered_set<int> s;
    s.insert(1);

    while (!q.empty()) {
        int from = q.front();
        q.pop();

        for (int to : g[from]) {
            if (s.count(to)) continue;
            s.insert(to);
            q.push(to);
        }
    }

    cout << (int)s.size();

    return 0;
}