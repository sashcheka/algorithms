#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> pmin(n, a[0]);
    vector<int> smax(n, a[n - 1]);
    for (int i = 1; i < n; i++) pmin[i] = min(pmin[i - 1], a[i]);
    for (int i = n - 2; i >= 0; i--) smax[i] = max(smax[i + 1], a[i]);
    string ans;
    for (int i = 0; i < n; i++) {
        if (a[i] == pmin[i] || a[i] == smax[i]) ans += '1';
        else ans += '0';
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
