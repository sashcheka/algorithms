#include <bits/stdc++.h>
using namespace std;

int h, w, n, full_mask;
vector<vector<long long>> a;
vector<vector<int>> adj;
long long ans = 0;

void dfs(int mask, long long XOR) {
    if (mask == full_mask) {
        ans = max(ans, XOR);
        return;
    }

    int k = 0;
    while (mask & (1 << k)) k++;
    int k_bit = 1 << k;
    int i = k / w;
    int j = k % w;

    dfs(mask | k_bit, XOR ^ a[i][j]);
    
    for (int nxt : adj[k]) {
        int nxt_bit = 1 << nxt;
        if (!(mask & nxt_bit)) dfs(mask | k_bit | nxt_bit, XOR);
    }
}

void solve() {
    cin >> h >> w;
    n = h * w;
    full_mask = (1 << n) - 1;
    a.assign(h, vector<long long>(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    
    adj.assign(n, {});
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int curr = i * w + j;

            // vertical
            if (i + 1 < h) {
                int nxt = (i + 1) * w + j;
                adj[curr].push_back(nxt);
                adj[nxt].push_back(curr);
            }

            // horizontal
            if (j + 1 < w) {
                int nxt = i * w + j + 1;
                adj[curr].push_back(nxt);
                adj[nxt].push_back(curr);
            }
        }
    }
    
    dfs(0, 0LL);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
