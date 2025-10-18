#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<string, int> dupa;
    int x = 0;
    for (int i = 0; i < n - k + 1; i++) {
        string substr = s.substr(i, k);
        dupa[substr]++;
        x = max(x, dupa[substr]);
    }
    cout << x << '\n';
    for (auto [substr, cnt] : dupa) {
        if (cnt == x) cout << substr << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}