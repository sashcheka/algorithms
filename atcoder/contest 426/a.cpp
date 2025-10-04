#include <bits/stdc++.h>
using namespace std;

void solve() {
    string x, y;
    cin >> x >> y;
    if (x == "Lynx") cout << "Yes";
    else if (x == y) cout << "Yes";
    else if (x == "Serval" && y == "Ocelot") cout << "Yes";
    else cout << "No";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}