#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    while (y * z <= x) {
        if (y * z == x) {
            cout << "Yes" << '\n';
            return;
        }
        x++;
        y++;
    }

    cout << "No" << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}