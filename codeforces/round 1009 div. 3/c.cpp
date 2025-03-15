#include<bits/stdc++.h>

using namespace std;

void solve() {
    int x;
    cin >> x;

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            int y = (1 << i) | (1 << j);
            if (y < x && x + y > (x ^ y) && x + (x ^ y) > y && y + (x ^ y) > x) {
                cout << y << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
