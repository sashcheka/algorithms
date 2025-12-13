#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    vector<int> visited(n, 0);
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        int v = i;
        int len = 0;
        while (!visited[v]) {
            visited[v] = 1;
            v = p[v];
            len++;
        }
        if (len >= 2) ans += 1LL * len * (len - 1) / 2;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}