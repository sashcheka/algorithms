#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
    }

    vector<vector<int>> cls(l);
    for (int i = 0; i < n; ++i) cls[i % l].push_back(a[i]);

    vector<vector<long long>> cost(l, vector<long long>(m, 0));
    for (int r = 0; r < l; ++r) {
        for (int t = 0; t < m; ++t) {
            long long c = 0;
            for (int x : cls[r]) {
                int d = t - x;
                if (d < 0) d += m;
                c += d;
            }
            cost[r][t] = c;
        }
    }

    long long best = (1LL<<60);
    function<void(int,int,long long)> dfs = [&](int r, int sum, long long cur) {
        if (r == l) {
            if (sum % m == 0) best = min(best, cur);
            return;
        }
        for (int t = 0; t < m; ++t) dfs(r + 1, (sum + t) % m, cur + cost[r][t]);
    };
    dfs(0, 0, 0);

    if (best == 0) cout << "O\n"; else cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
