#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int same_adj = 0;
    for (int i = 0; i + 1 < (int)s.size(); i++) {
        if (s[i] == s[i + 1]) same_adj++;
    }

    if (same_adj <= 2) cout << "YES" << "\n";
    else cout << "NO" << "\n";

    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
