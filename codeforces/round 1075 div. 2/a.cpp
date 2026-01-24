#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, h, l;
    cin >> n >> h >> l;
    if (h > l) swap(h, l);
    int cnt_h = 0;
    int cnt_l = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a <= h) cnt_h++;
        if (a <= l) cnt_l++;
    }
    int ans = min(cnt_h, cnt_l / 2);
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
