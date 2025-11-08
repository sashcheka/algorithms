#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, b;
    cin >> h >> b;
    cout << max(0, h - b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}