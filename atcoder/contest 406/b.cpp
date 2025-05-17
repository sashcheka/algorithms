#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    long long MAX = 1;
    for (int i = 0; i < k; ++i) MAX *= 10;
    MAX -= 1;

    long long res = 1;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;

        if (res > MAX / a) res = 1;
        else res *= a;
    }

    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}