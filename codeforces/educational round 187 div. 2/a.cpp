#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    int k = d / m + 1;
    int ans = (n + k - 1) / k;
    cout << ans << '\n';
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
