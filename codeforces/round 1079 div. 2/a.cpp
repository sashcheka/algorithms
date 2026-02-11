#include<bits/stdc++.h>
using namespace std;

void solve() {
    int x;
    cin >> x;
    int temp = x;
    int x_digits_cnt = 0;
    while (temp) {
        x_digits_cnt++;
        temp /= 10;
    }
    int hi = (x_digits_cnt + 1) * 9;
    int ans = 0;
    for (int cand = x + 1; cand <= x + hi + 1; cand++) {
        int temp = cand;
        int digits_sum = 0;
        while (temp) {
            digits_sum += temp % 10;
            temp /= 10;
        }
        if (cand - digits_sum == x) ans++;
    }

    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
