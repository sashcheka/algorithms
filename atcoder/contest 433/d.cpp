#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // unordered_map solution
    vector<unordered_map<int, int>> rem(11);
    for (int i = 0; i < n; i++) rem[to_string(a[i]).size()][a[i] % m]++;

    // binary search solution
    // vector<vector<int>> rem(11);
    // for (int i = 0; i < n; i++) rem[to_string(a[i]).size()].push_back(a[i] % m);
    // for (int i = 0; i < 11; i++) sort(rem[i].begin(), rem[i].end());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 1; k < 11; k++) {
            a[i] *= 10;
            a[i] %= m;
            int key = (m - a[i]) % m;
            
            // unordered_map solution
            ans += rem[k][key];

            // binary search solution
            // auto lo = lower_bound(rem[k].begin(), rem[k].end(), key);
            // auto hi = lower_bound(rem[k].begin(), rem[k].end(), key + 1);
            // ans += hi - lo;
        }
    }

    cout << ans << '\n';
    return;        
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}