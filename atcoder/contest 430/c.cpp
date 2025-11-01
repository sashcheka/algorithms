#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    vector<int> pa(n + 1, 0);
    vector<int> pb(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pa[i] = pa[i - 1] + (s[i - 1] == 'a');
        pb[i] = pb[i - 1] + (s[i - 1] == 'b');
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int lo = lower_bound(pa.begin() + i, pa.end(), pa[i - 1] + a) - pa.begin();
        auto hi = upper_bound(pb.begin() + i, pb.end(), pb[i - 1] + b - 1) - pb.begin() - 1;
        if (lo <= hi) ans += hi - lo + 1;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}