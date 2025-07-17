#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> casino(n);
    for (int i = 0; i < n; i++) {
        int l, r, real;
        cin >> l >> r >> real;
        casino[i] = {l, r, real};
    }

    sort(casino.begin(), casino.end());
    priority_queue<int, vector<int>> pq; // real

    int ans = k;
    int curr = k;
    for (int i = 0; i < n; i++) {
        int l = casino[i][0];
        int r = casino[i][1];
        int real = casino[i][2];

        if (l <= curr && curr <= r) pq.push(real);

        while (!pq.empty()) {
            curr = max(curr, pq.top());
            pq.pop();
            ans = max(ans, curr);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
