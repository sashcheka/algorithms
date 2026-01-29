#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mn = INT_MAX;
    int mx = INT_MIN;
    int prev = -1;
    bool sorted = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (prev != -1 && prev > a[i]) sorted = false;
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        prev = a[i];
    }
    if (sorted) {
        cout << -1 << '\n';
        return;
    }
    vector<int> sa = a;
    sort(sa.begin(), sa.end());
    int best = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] == sa[i]) continue;
        int cand = max(mx - a[i], a[i] - mn);
        best = min(best, cand);
    }
    cout << best << '\n';
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
