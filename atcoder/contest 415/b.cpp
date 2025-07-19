#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<int> packages;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') {
            packages.push_back(i+1);
        }
    }

    for (int i = 0; i < packages.size() - 1; i += 2) {
        cout << packages[i] << ',' << packages[i+1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}