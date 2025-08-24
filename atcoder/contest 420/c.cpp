#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    long long ans = 0;
    for (int i = 0; i < n; i++) ans += min(a[i], b[i]);

    for (int i = 0; i < q; i++) {
        char c;
        int x, v;
        cin >> c >> x >> v;
        x--;
        if (c == 'A') {
            ans -= min(a[x], b[x]);
            a[x] = v;
            ans += min(a[x], b[x]);
        } else if (c == 'B') {
            ans -= min(a[x], b[x]);
            b[x] = v;
            ans += min(a[x], b[x]);
        }

        cout << ans << '\n';
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}