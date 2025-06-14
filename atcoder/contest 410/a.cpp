#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int k;
    cin >> k;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (k <= a[i]) ans++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}