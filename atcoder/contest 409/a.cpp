#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string t, a;
    cin >> t >> a;

    for (int i = 0; i < n; i++) {
        if (t[i] == a[i] && a[i] == 'o') {
            cout << "Yes";
            return;
        }
    }

    cout << "No";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}