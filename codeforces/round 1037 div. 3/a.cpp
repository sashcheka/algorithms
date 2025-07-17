#include<bits/stdc++.h>
using namespace std;

void solve() {
    int x;
    cin >> x;
    int y = x;
    while (x) {
        y = min(y, x%10);
        x/=10;
    }
    cout << y << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
