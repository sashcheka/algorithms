#include<bits/stdc++.h>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    if (x % 2 == 1 && y % 2 == 1) cout << "NO" << "\n";
    else cout << "YES" << "\n";
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
