#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    unordered_map<string, string> dupa = {
        {"red", "SSS"},
        {"blue", "FFF"},
        {"green", "MMM"}
    };

    if (dupa.find(s) == dupa.end()) cout << "Unknown";
    else cout << dupa[s];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}