#include <bits/stdc++.h>
using namespace std;

vector<string> res;

void dfs(string curr, int k, vector<string>& s) {
    if (k <= 0) {
        res.push_back(curr);
        return;
    }

    for (int i = 0; i < s.size(); i++) dfs(curr+s[i], k-1, s);
}

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = 0; i < n; i++) dfs(s[i], k-1, s);
    sort(res.begin(), res.end());

    cout << res[x-1];    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}