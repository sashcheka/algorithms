#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long x, c;
    cin >> x >> c;
    long long y = (x * 1000) / (c + 1000);
    y -= y % 1000;
    cout << y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}