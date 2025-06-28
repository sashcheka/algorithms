#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    unordered_set<char> setik(t.begin(), t.end());

    for (int i = 1; i < s.size(); i++) {
        if (isupper(s[i]) && !setik.count(s[i - 1])) {
            cout << "No";
            return;
        }
    }

    cout << "Yes";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}