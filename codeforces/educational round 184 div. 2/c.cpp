#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<long long> p(n + 1, 0);
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i - 1];
    long long total = p[n];
    long long best_left = LLONG_MIN;
    long long best_gain = 0;
    for (int i = 1; i <= n; i++) {
        long long right = 1LL*i*i + i - p[i];
        long long left = -1LL*i*i + i + p[i - 1];
        best_left = max(best_left, left);
        best_gain = max(best_gain, right + best_left);
    }
    cout << total + best_gain << '\n';
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