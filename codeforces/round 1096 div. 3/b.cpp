#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int d = 0;
    for (const char& ch : s) {
        if (ch == '(') d++;
        else if (ch == ')') d--;
    }
    if (d == 0) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
