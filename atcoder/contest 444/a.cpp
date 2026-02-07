#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int d1 = n % 10;
    n /= 10;
    int d2 = n % 10;
    n /= 10;
    int d3 = n % 10;
    if (d1 == d2 && d2 == d3) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}