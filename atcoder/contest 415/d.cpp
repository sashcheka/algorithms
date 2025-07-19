#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    int m;
    cin >> n >> m;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> mpq; // diff, a
    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        long long diff = a - b;
        mpq.push({diff, a});
    }

    long long ans = 0;
    while (!mpq.empty()) {
        auto [diff, a] = mpq.top();

        if (a > n) {
            mpq.pop();
            continue;
        }

        long long rep = (n - a) / diff + 1;
        ans += rep;
        n -= rep * diff;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}