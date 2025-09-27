#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n + 1, 0);
    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    long long offset = 0;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int c;
            cin >> c;
            offset += c;
            offset %= n;
        } else if (type == 2) {
            long long l, r;
            cin >> l >> r;
            l--;
            long long right = ((r + offset) / n) * a[n] + a[(r + offset) % n];
            long long left = ((l + offset) / n) * a[n] + a[(l + offset) % n];
            long long ans = right - left;
            cout << ans << '\n';
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}