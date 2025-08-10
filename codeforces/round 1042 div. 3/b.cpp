#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) cout << -1 << ' ';

        if (i < n - 1 && i % 2 == 1) cout << 3 << ' ';
        else if (i % 2 == 1) cout << 2 << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
