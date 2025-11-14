#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n = 1e12;
    long long x, y, k;
    cin >> x >> y >> k;

    if (y == 1) {
        cout << -1 << '\n';
        return;
    }

    long long pos = k;
    for (long long i = 0; i < x; i++) {
        if (pos > n) {
            pos = n + 1;
            break;
        }
        long long block = (pos - 1) / (y - 1);
        long long offset = (pos - 1) % (y - 1);
        pos = block * y + offset + 1;
    }

    if (pos > n) cout << -1 << '\n';
    else cout << pos << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}