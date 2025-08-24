#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    int ans;
    if ((x + y) % 12 == 0) cout << 12;
    else if (x + y > 12) cout << (x + y) % 12;
    else cout << x + y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}