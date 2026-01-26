#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int p = 3;
    cout << (n % 2 ? n - 1 : n) << ' '; 
    for (int i = 1; i < n - 1; i++) {
        cout << p << ' ';
        if (p % 2) p--;
        else p += 3;
    }
    cout << 1 << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
