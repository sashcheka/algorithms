#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n >= 3 && s[n-3] == 't' && s[n-2] == 'e' && s[n-1] == 'a') cout << "Yes";
    else cout << "No";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}