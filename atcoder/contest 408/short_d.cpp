#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int total_ones = 0;
    for (char ch : s) if (ch == '1') total_ones++;

    int best_cost = total_ones;
    int max_diff = 0;  // max of (prefix_zeros - prefix_ones) seen so far

    int prefix_ones = 0, prefix_zeros = 0;
    for (int i = 0; i <= n; ++i) {
        int diff = prefix_zeros - prefix_ones;
        best_cost = min(best_cost, total_ones + diff - max_diff);
        max_diff = max(max_diff, diff);

        if (i < n) {
            prefix_ones += (s[i] == '1');
            prefix_zeros += (s[i] == '0');
        }
    }

    cout << best_cost << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}