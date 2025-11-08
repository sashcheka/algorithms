#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, n;
    cin >> x >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    
    int q;
    cin >> q;
    vector<bool> attached(n, false);
    for (int i = 0; i < q; i++) {
        int p;
        cin >> p;
        p--;
        if (attached[p]) {
            x -= w[p];
            attached[p] = false;
        } else {
            x += w[p];
            attached[p] = true;
        }
        cout << x << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}