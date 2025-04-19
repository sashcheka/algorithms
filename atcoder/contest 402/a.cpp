#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    string t;
    for (const char& ch : s) {
        if (ch - 97 < 0) t += ch;
    }

    cout << t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}