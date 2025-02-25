#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, p;
    cin >> n >> k >> p;

    if ((abs(k) + p - 1) / p > n) {
        cout << -1 << '\n';
        return;
    } else {
        cout << (abs(k) + p - 1) / p << '\n';
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
