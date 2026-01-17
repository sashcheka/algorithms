#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int zeros = 0;
    int ones = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 0) zeros++;
        if (a == 1) ones++;
    }

    if (zeros == 0) {
        cout << "NO" << '\n';
    } else if (ones == 0) {
        cout << (zeros == 1 ? "YES" : "NO") << '\n';
    } else {
        cout << "YES" << '\n';
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
