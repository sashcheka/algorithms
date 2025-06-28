#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> adj(n, vector<bool>(n, false));
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a][b] = adj[b][a] = true;
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++) p[i] = i;
    int best = INT_MAX;

    do {
        vector<bool> seen(n, false);
        bool ok = true;
        for (int i = 0; i < n; i++){
            if (!seen[i]){
                int len = 0, cur = i;
                do {
                    seen[cur] = true;
                    cur = p[cur];
                    len++;
                } while (!seen[cur]);
                if (len < 3) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) continue;

        int keep = 0;
        for (int u = 0; u < n; u++){
            int v = p[u];
            if (adj[u][v] && adj[u][v]) keep++;
        }

        int remove = m - keep;
        int add = n - keep;
        best = min(best, remove + add);
    } while (next_permutation(p.begin(), p.end()));

    cout << best << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
