#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    unordered_set<int> curr, total;
    for (int i = 0; i < n; i++) {
        curr.insert(a[i]);
        total.insert(a[i]);
        if (curr.size() == total.size()) {
            ans++;
            curr.clear();
        }
    }

    cout << ans << '\n';
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