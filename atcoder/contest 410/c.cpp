#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) a[i] = i + 1;

    int offset = 0;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            a[(p + offset) % n] = x;
        } else if (type == 2) {
            int p;
            cin >> p;
            p--;
            cout << a[(p + offset) % n] << '\n';
        } else if (type == 3) {
            int k;
            cin >> k;
            offset = (offset + k) % n;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}