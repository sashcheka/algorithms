#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = s.size();
    string t = "";
    for (int i = 0; i < n - m; i++) {
        t += 'o';
    }
    t += s;
    cout << t << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}