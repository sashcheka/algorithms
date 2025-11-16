#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 1;
    if (b < a && (long long)b * n > a) ans += 1;
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
