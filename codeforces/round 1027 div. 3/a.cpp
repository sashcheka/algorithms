#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int year = 0;
    for (int i = 3; i >= 0; i--) {
        year += (s[i] - '0') * pow(10, 3 - i);
    }

    for (int i = 0; i * i <= year; i++) {
        if (i * i == year) {
            cout << 0 << ' ' << i << '\n';
            return;
        }
    }

    cout << -1 << '\n';
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
