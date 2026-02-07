#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int num = 1; num <= n; num++) {
        int temp = num;
        int dsum = 0;
        while (temp) {
            dsum += temp % 10;
            temp /= 10;
        }
        if (dsum == k) ans++;
    }
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}