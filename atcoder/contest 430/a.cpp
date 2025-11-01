#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c >= a) {
        if (d >= b) {
            cout << "No";
        } else {
            cout << "Yes";
        }
    } else {
        cout << "No";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}