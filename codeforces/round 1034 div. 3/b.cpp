#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, j, k;
    cin >> n >> j >> k;
    j--;
    vector<int> a(n);
    int MAX = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        MAX = max(MAX, a[i]);
    }
    if (k > 1) cout << "YES" << '\n';
    else cout << (a[j] == MAX ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}