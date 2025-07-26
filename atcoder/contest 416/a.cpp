#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l, r;
    string s;
    cin >> n >> l >> r >> s;

    for (int i = l-1; i < r; i++) {
        if (s[i] != 'o') {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}