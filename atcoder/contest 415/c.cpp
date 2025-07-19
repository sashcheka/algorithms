#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<bool> is_safe(1<<n, true);
    for (int i = 0; i < (1<<n) - 1; i++) if (s[i] == '1') is_safe[i+1] = false;

    vector<bool> visited(1<<n, false);
    visited[0] = true;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int bit = 0; bit < n; bit++) {
            if (curr & (1<<bit)) continue;

            int next = curr | (1<<bit);
            if (is_safe[next] && !visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }

    if (visited[(1<<n)-1]) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}