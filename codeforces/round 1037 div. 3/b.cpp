#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int streak = a[0] == 0 ? 1 : 0;
    int rest_end = 0;
    int ans = 0;
    if (streak >= k) {
        ans++;
        rest_end = 2;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            streak++;
        } else {
            streak = 0;
        }

        if (i >= rest_end && streak >= k) {
            streak = i + 1 < n && a[i + 1] == 0 ? -1 : 0;
            ans++;
            rest_end = i + 2;
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
