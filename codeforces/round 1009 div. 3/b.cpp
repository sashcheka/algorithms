#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) {
        cout << a[0] << '\n';
        return;
    }

    for (int i = 1; i < n; i++) {
        int x = a[i - 1] + a[i] - 1;
        a[i] = x;
    }

    cout << a[n - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
