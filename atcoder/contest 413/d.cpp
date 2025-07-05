#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool f(int n, vector<ll> a, bool asc) {
    sort(a.begin(), a.end(), [&](ll x, ll y){
        ll abs_x = llabs(x), abs_y = llabs(y);
        if (abs_x != abs_y) return asc ? abs_x < abs_y : abs_x > abs_y;
        return x < y;
    });

    bool equal = true;
    for (int i = 1; i < n; i++) {
        if (llabs(a[i]) != llabs(a[0])) {
            equal = false;
            break;
        }
    }

    if (equal) {
        int cnt = 0;
        for (ll x : a) cnt += (x == a[0]);
        if (cnt == n) return true;

        int pos = 0;
        int neg = 0;
        for (ll x : a) {
            if (x > 0) pos++;
            else neg++;
        }
        return abs(pos - neg) <= 1;
    }

    ll x0 = a[0];
    ll x1 = a[1];
    for (int i = 1; i < n; i++) {
        if (a[i] * x0 != x1 * a[i - 1]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    bool ok = f(n, a, true) || f(n, a, false);
    if (ok) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}