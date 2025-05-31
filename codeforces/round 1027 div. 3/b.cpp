#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int zeros = 0;
    for (char ch : s) if (ch == '0') zeros++;
    int ones = n - zeros;

    while (k--) {
        if (zeros > ones) {
            zeros -= 2;
        } else {
            ones -= 2;
        }
    }

    if (zeros == ones) cout << "YES" << '\n';
    else cout << "NO" << '\n';

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
