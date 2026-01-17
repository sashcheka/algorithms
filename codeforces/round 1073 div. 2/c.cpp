#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool has10 = false;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '1' && s[i] == '0') {
            has10 = true;
            break;
        }
    }
    if (!has10) {
        cout << "Bob" << '\n';
        return;
    }
    int z = 0;
    for (char ch : s) if (ch == '0') z++;
    vector<int> idx;
    for (int i = 0; i < z; i++) if (s[i] == '1') idx.push_back(i + 1);
    for (int i = z; i < n; i++) if (s[i] == '0') idx.push_back(i + 1);
    cout << "Alice" << '\n';
    int m = idx.size();
    cout << m << '\n';
    for (int i = 0; i < m; i++) cout << idx[i] << " \n"[i == m - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
