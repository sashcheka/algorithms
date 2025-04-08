#include<bits/stdc++.h>

using namespace std;

void solve() {
    int k;
    cin >> k;

    if (k % 2) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
