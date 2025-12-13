#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> setik;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        if (r + 1 >= n || c + 1 >= n) continue;
        if (setik.count({r, c}) || setik.count({r + 1, c}) || setik.count({r, c + 1}) || setik.count({r + 1, c + 1})) continue;
        setik.insert({r, c});
        setik.insert({r + 1, c});
        setik.insert({r, c + 1});
        setik.insert({r + 1, c + 1});
        ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}