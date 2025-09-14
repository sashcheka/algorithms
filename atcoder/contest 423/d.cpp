#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    long long n, k;
    cin >> n >> k;

    vector<vector<ll>> g(n);
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        g[i] = {a, b, c};
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; // left, count

    vector<ll> ans(n);
    ll space = k;
    ll time = 0;
    for (int i = 0; i < n; i++) {
        time = max(time, g[i][0]);

        while (!pq.empty() && pq.top().first <= time) {
            space += pq.top().second;
            pq.pop();
        }

        while (space < g[i][2]) {
            ll to_leave = pq.top().first;
            time = to_leave;

            while (!pq.empty() && pq.top().first <= time) {
                space += pq.top().second;
                pq.pop();
            }
        }

        ans[i] = time;
        space -= g[i][2];
        pq.push({time + g[i][1], g[i][2]});
    }

    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}