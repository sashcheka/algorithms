#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> cands(n, 0);

    for (int i = 0; i < n - 1; i++) {
        if (s[i] != '0') {
            cands[i + 1] = cands[i] + 1;
        } else {
            cands[i + 1] = cands[i];
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (s[i] != '0') {
            ans = min(ans, cands[i] + n - i - 1);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
