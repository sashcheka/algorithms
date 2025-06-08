#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int first = -1;
    int last = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            first = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 1) {
            last = i;
            break;
        }
    }

    if (last - first + 1 <= x) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
