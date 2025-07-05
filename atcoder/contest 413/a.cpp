#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int total = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        total += a;
    }
    if (total <= m) cout << "Yes";
    else cout << "No";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}