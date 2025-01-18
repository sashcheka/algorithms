#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> adj(n);
    for (int i = 0; i < n; i++) cin >> adj[i];

    vector<int> p(n);
    for (int i = 0; i < n; i++) p[i] = i;
    sort(p.begin(), p.end(), [&](const int& a, const int& b) {
        if (adj[a][b] == '1') return a < b;
        return a > b;
    });

    for (const int& node : p) cout << node + 1 << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
