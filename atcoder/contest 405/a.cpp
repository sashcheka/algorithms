#include<bits/stdc++.h>

using namespace std;

void solve() {
    int r, x;
    cin >> r >> x;

    if (x == 1) {
        if (1600 <= r && r <= 2999) cout << "Yes";
        else cout << "No";
    } else if (x == 2) {
        if (1200 <= r && r <= 2399) cout << "Yes";
            else cout << "No";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}