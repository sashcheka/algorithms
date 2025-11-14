#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '*' && (s[i] == '*' || s[i] == '<')) {
            cout << -1 << '\n';
            return;
        } else if (s[i - 1] == '>' && (s[i] == '*' || s[i] == '<')) {
            cout << -1 << '\n';
            return;
        }
    }


    vector<int> left(n, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == '<') left[i] = 1 + (i > 0 ? left[i - 1] : 0);
        else left[i] = 0;
    }

    vector<int> right(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '>') right[i] = 1 + (i + 1 < n ? right[i + 1] : 0);
        else right[i] = 0;
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '<') ans = max(ans, left[i]);
        if (s[i] == '>') ans = max(ans, right[i]);
        if (s[i] == '*') {
            if (i - 1 >= 0 && s[i - 1] == '<') ans = max(ans, 1 + left[i - 1]);
            if (i + 1 < n && s[i + 1] == '>') ans = max(ans, 1 + right[i + 1]);
        }
    }

    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}