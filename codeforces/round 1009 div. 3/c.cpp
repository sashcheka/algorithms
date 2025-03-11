#include<bits/stdc++.h>

using namespace std;

void solve() {
    int x;
    cin >> x;

    int temp = x;
    int bits = 0;
    while (temp) {
        if (temp & 1)bits++;
        temp >>= 1;
    }
    if (bits == 1) {
        cout << -1 << '\n';
        return;
    }

    temp = x + 1;
    bits = 0;
    while (temp) {
        if (temp & 1) bits++;
        temp >>= 1;
    }
    if (bits == 1) {
        cout << -1 << '\n';
        return;
    }

    for (int y = 1; y < x; y++) {
        int lower = x - y + 1;
        int upper = x + y - 1;
 
        int XOR = x ^ y;
        if (XOR >= lower && XOR <= upper) {
            cout << y << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
