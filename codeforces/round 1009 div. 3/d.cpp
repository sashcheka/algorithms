#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> x(n);
    vector<ll> r(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> r[i];

    unordered_map<ll, ll> dupa;
    for (int i = 0; i < n; i++) {
        ll xi = x[i];
        ll ri = r[i];

        for (ll dx = xi - ri; dx <= xi + ri; dx++) {
            ll cand = 2 * (ll)sqrt(ri * ri - (dx - xi) * (dx - xi)) + 1;
            dupa[dx] = max(dupa[dx], cand);
        }
    }

    ll res = 0;
    for (auto [dx, count] : dupa) res += count;
    cout << res << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
