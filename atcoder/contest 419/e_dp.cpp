#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
    }

    const long long INF = LLONG_MAX;
    vector<long long> dp(m, INF), ndp(m, INF);
    dp[0] = 0;
    for (int r = 0; r < l; r++) {
        vector<long long> freq(m, 0);
        long long sum = 0;
        long long k = 0;
        for (int i = r; i < n; i += l) {
            freq[a[i]]++;
            sum += a[i];
            k++;
        }

        for (int t = 1; t < m; t++) freq[t] += freq[t - 1];
        
        vector<long long> cost(m);
        for (int t = 0; t < m; t++) cost[t] = 1LL*t*k - sum + 1LL*m*(k - freq[t]);
        
        fill(ndp.begin(), ndp.end(), INF);
        for (int s = 0; s < m; s++) {
            if (dp[s] >= INF) continue;

            for (int t = 0; t < m; ++t) {
                int ns = (s + t) % m;
                long long v = dp[s] + cost[t];
                if (v < ndp[ns]) ndp[ns] = v;
            }
        }
        dp.swap(ndp);
    }

    cout << dp[0] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}