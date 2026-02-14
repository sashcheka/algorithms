#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long p, q;
    cin >> p >> q;
    long long d = q - p;
    if (p >= q || p < 2*d) {
        cout << "Alice" << "\n";
    } else {
        cout << "Bob" << "\n";
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
