#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            if (a[i - 1] > a[i]) {
                ans += a[i - 1] - a[i];
                a[i - 1] = a[i];
            }
            if (i < n - 1 && a[i + 1] > a[i]) {
                ans += a[i + 1] - a[i];
                a[i + 1] = a[i];
            }
            if (i < n - 1 && (a[i - 1] + a[i + 1]) > a[i]) {
                int rem = a[i - 1] + a[i + 1] - a[i];
                ans += rem;
                a[i + 1] -= min(rem, a[i + 1]);
                rem -= min(rem, a[i + 1]);
                a[i - 1] -= rem;
            }
        }
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
