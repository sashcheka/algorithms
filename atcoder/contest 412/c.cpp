#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> S(n);
    for (int i = 0; i < n; i++) cin >> S[i];
    
    vector<ll> interior;
    interior.reserve(n - 2);
    for (int i = 1; i < n - 1; i++) interior.push_back(S[i]);
    sort(interior.begin(), interior.end());

    ll curr = S[0];
    int ans = 1;
    int idx = 0;
    int m = interior.size();

    while (true) {
        if (S[n-1] <= 2LL * curr) {
            cout << ans + 1 << '\n';
            return;
        }

        int start = idx;
        while (idx < m && interior[idx] <= 2LL * curr) idx++;

        if (start == idx) {
            cout << -1 << '\n';
            return;
        }

        curr = interior[idx - 1];
        ans++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
