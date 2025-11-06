#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int x;
    cin >> x;

    if (n == 1) {
        if (a[0] == x) cout << "Yes" << '\n';
        else cout << "No" << '\n';
        return;
    }

    bool less = false;
    bool more = false;
    for (int i = 0; i < n; i++) {
        if (a[i] <= x) less = true;
        if (a[i] >= x) more = true;
    }

    if (less && more) cout << "Yes" << '\n';
    else cout << "No" << '\n';
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
