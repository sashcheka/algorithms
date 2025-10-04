#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    map<char, int> dupa;
    for (char ch : s) dupa[ch]++;
    for (auto [ch, cnt] : dupa) {
        if (cnt == 1) {
            cout << ch;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}