#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<long long> prefix(n, 0);
    prefix[0] = 1;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) prefix[i] = prefix[i - 1] + 1;
        else prefix[i] = 1;
    }
    vector<long long> suffix(n, 0);
    suffix[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == s[i + 1]) suffix[i] = suffix[i + 1] + 1;
        else suffix[i] = 1;
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        if ((s[i - 1] - '0') + 1 == (s[i] - '0')) ans += min(prefix[i - 1], suffix[i]);
    }
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}