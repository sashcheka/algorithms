#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    unordered_map<int, int> dupa;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dupa[a[i]]++;
        cnt[dupa[a[i]]]++;
    }

    int ans = 0;
    for (int i = 0; i < n + 1; i++) {
        ans = max(ans, cnt[i] * i);
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
