#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    long long ones = 0;
    long long total = 0;
    long long covered_ones = 0;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        if (c == 1) {
            ones++;
        } else {
            total += c;
            covered_ones += c / 2 - 1;
        }
    }

    if (ones == n - 1) covered_ones++;

    long long ans = total + min(ones, covered_ones);

    if (ans < 3) ans = 0;
    cout << ans << "\n";

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
