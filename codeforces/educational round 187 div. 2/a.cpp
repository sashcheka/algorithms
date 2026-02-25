#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    if (m > d) {
        cout << n << '\n';
        return;
    }
    int ans = 0;
    while (n > 0) {
        n--;
        n -= d / m;
        ans++;
    }
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
