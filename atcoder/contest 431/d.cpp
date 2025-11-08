#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int total_weight = 0;
    long long body_happiness = 0;
    vector<tuple<int, long long, long long>> v(n);
    for (int i = 0; i < n; i++) {
        int w;
        long long h, b;
        cin >> w >> h >> b;
        v[i] = {w, h, b};
        total_weight += w;
        body_happiness += b;
    }

    long long ans = 0;
    int m = total_weight / 2;
    vector<long long> dp(m + 1, LLONG_MIN);
    dp[0] = body_happiness;
    for (int i = 0; i < n; i++) {
        auto [w, h, b] = v[i];
        if (b >= h) continue;
        for (int j = m; j >= w; j--) {
            if (dp[j - w] == LLONG_MIN) continue;
            dp[j] = max(dp[j], dp[j - w] + h - b);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}