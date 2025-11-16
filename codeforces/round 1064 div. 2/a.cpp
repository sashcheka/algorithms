#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char last = s[n - 1];
    unordered_map<char, int> dupa;
    for (char ch : s) dupa[ch]++;
    cout << n - dupa[last] << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
