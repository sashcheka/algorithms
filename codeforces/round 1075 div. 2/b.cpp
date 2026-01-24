#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long x;
    cin >> n >> x;
    long long best = LLONG_MIN;
    long long free_dist = 0;
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        best = max(best, a * b - c);
        free_dist += a * (b - 1);
    }

    if (free_dist >= x) {
        cout << 0 << '\n';
        return;
    }
    if (best <= 0) {
        cout << -1 << '\n';
        return;
    }

    long long rollbacks = (x - free_dist + best - 1) / best;
    cout << rollbacks << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
