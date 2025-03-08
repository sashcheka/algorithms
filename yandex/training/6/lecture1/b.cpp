#include<bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a == 0 && c != 0) {
        cout << 1 << ' ' << c + 1;
        return;
    }

    if (b == 0 && d != 0) {
        cout << 1 << ' ' << d + 1;
        return;
    }

    if (c == 0 && a != 0) {
        cout << a + 1 << ' ' << 1;
        return;
    }

    if (d == 0 && b != 0) {
        cout << b + 1 << ' ' << 1;
        return;
    }

    int sum = INT_MAX;
    int m;
    int n;

    int c1 = max(a, b) + 1 + 1;
    if (c1 < sum) {
        sum = c1;
        m = max(a, b) + 1;
        n = 1;
    }

    int c2 = 1 + max(c, d) + 1;
    if (c2 < sum) {
        sum = c1;
        m = 1;
        n = max(c, d) + 1;
    }

    if (a >= b && c >= d || a <= b && c <= d) {
        int c3 = min(a, b) + 1 + min(c, d) + 1;
        if (c3 < sum) {
            sum = c3;
            m = min(a, b) + 1;
            n = min(c, d) + 1;
        }
    }

    cout << m << ' ' << n;

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}