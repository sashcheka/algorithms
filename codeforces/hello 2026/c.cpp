#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, m, k;
    cin >> n >> m >> k;

    long long left = k - 1;
    long long right = n - k;

    long long ans = 1;

    for (long long l = 0; l <= left; l++) {
        long long best_r = -1;

        long long upper_left = m - 2LL * l + 1;
        if (upper_left >= 0) {
            long long r = min({right, l, upper_left});
            best_r = max(best_r, r);
        }

        long long upper_right = (m - l + 1) / 2;
        if (upper_right >= l) {
            long long r = min(right, upper_right);
            best_r = max(best_r, r);
        }

        if (best_r >= 0) ans = max(ans, 1 + l + best_r);
    }

    ans = min(ans, n);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
