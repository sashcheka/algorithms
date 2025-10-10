#include<bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    if ((x&y) == (x&z) && (x&y) == (y&z)) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}