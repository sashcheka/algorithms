#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int total_ones = 0;
    for (char ch : s) if (ch == '1') total_ones++;

    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + (s[i - 1] == '1' ? 1 : 0);

    vector<int> diff(n + 1, 0);
    for (int i = 0; i <= n; i++) diff[i] = (i - prefix[i]) - prefix[i]; // 0s - 1s

    int max_val = diff[0];
    int best = total_ones;

    for (int i = 0; i <= n; i++) {
        max_val = max(max_val, diff[i]);
        int candidate = total_ones + (diff[i] - max_val);
        best = min(best, candidate);
    }

    cout << best << '\n';
 }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}