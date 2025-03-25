#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << -1 << '\n';
        return;
    }

    int j = 0;
    for (int i = 1; i <= n; i += 2) {
        cout << i << ' ';
        j++;
    }
    for (int i = 2; i <= n; i += 2) {
        cout << i << ' ';
        j++;
    }
    
    cout << '\n';
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
