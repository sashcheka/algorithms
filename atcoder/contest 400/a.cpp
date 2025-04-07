#include<bits/stdc++.h>

using namespace std;

void solve() {
    int a;
    cin >> a;
    if (400 % a == 0) cout << 400 / a;
    else if (a == 1) cout << 400;
    else if (a == 400) cout << 1;
    else cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}