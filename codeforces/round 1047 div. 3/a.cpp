#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long k, x;
    cin >> k >> x;
    while (k--) {
        x *= 2;
    }
    cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
