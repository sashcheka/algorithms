#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long m;
    cin >> n >> m;

    vector<long long> a(n);
    long long sum_a = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum_a += a[i];
    }

    vector<long long> b(n);
    long long sum_b = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sum_b += b[i];
    }

    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());

    int idx = 0;
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        while (idx < n && b[idx] + a[i] < m) idx++;
        if (idx >= n) break;
        cnt++;
        idx++;
    }

    cout << sum_a + sum_b - cnt*m << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}