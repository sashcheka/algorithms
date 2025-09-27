#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (long long)pow(-1, i) * pow(i, 3);
    }

    cout << ans;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}