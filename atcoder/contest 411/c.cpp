#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<bool> color(n + 2, false); // true - black
    int ans = 0;
    int a;
    for (int i = 0; i < q; i++) {
        cin >> a;
        bool l = color[a - 1];
        bool r = color[a + 1];

        if (color[a]) {
            if (l && r) {
                ans++;
            } else if (!l && !r) {
                ans--;
            }
        } else {
            if (l && r) {
                ans--;
            } else if (!l && !r) {
                ans++;
            }
        }

        color[a] = !color[a];
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}