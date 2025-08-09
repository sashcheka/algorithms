#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string t;
    cin >> n >> t;

    vector<long long> cnt = {1, 0}; // {even, odd} counts
    long long ans = 0;
    int p = 0;
    for (char ch : t) {
        if (ch == '0') p ^= 1;
        ans += cnt[p];
        cnt[p]++;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}