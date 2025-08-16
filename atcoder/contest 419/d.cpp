#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    vector<int> swaps(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        swaps[l - 1]++;
        swaps[r]--;
    }

    string ans;
    for (int i = 0; i < n; i++) {
        if (swaps[i] % 2) ans += t[i];
        else ans += s[i];
        swaps[i + 1] += swaps[i];
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}