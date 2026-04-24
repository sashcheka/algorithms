#include<bits/stdc++.h>

using namespace std;

// valid bruteforce (answer will be found before TL in the first 50 numbers 
// because LCM(1, 2, ..., 49, 50) has 10^21 degree)
void solve() {
    long long x, y;
    cin >> x >> y;

    bool possible = false;
    for (long long z = x + x; z < y; z += x) {
        if (y % z != 0) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return;
}

void solve() {
    long long x, y;
    cin >> x >> y;

    if (x * 2 == y) cout << "NO" << "\n";
    else cout << "YES" << "\n";

    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
