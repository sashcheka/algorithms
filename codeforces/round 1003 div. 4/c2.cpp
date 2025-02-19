#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll INF = LLONG_MAX;


void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> va(n), vb(m);
    for (ll &i : va) cin >> i;
    for (ll &i : vb) cin >> i;

    sort(vb.begin(), vb.end());

    va.insert(va.begin(), -INF);
    n++;

    for (ll i = 1; i < n; i++) {
        auto it = lower_bound(vb.begin(), vb.end(), 69, [&](ll b, ll placeholder) {
            assert(placeholder == 69);
            return b - va[i] < va[i - 1];
        });
        
        if (it == vb.end()) continue;
        ll b = *it;

        if (va[i] < va[i - 1] && b - va[i] < va[i - 1]) continue;

        ll cand1 = va[i] < va[i - 1] ? INF : va[i];
        ll cand2 = b - va[i] < va[i - 1] ? INF : b - va[i];
        va[i] = min(cand1, cand2);
    }

    if (is_sorted(va.begin(), va.end())) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll T; cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
