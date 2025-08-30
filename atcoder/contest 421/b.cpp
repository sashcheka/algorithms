#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long x, y;
    cin >> x >> y;
    long long temp = x + y;
    long long z = 0;
    while (temp) {
        z *= 10;
        z += temp % 10;
        temp /= 10;
    }
    int n = 7;
    while (n--) {
        x = y;
        y = z;
        temp = x + y;
        z = 0;
        while (temp) {
            z *= 10;
            z += temp % 10;
            temp /= 10;
        }
    }
    cout << z;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}