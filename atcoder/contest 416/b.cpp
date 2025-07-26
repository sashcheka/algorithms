#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    string t = s;
    bool ok = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.' && ok) {
            t[i] = 'o';
            ok = false;
        } else if (s[i] == '#') {
            ok = true;
        }
    }

    cout << t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}