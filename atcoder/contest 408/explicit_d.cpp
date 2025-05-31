#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int total_ones = 0;
    for (char ch : s) if (ch == '1') total_ones++;

    vector<int> prefix_ones(n + 1, 0);
    vector<int> prefix_zeros(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix_ones[i] = prefix_ones[i - 1] + (s[i - 1] == '1' ? 1 : 0);
        prefix_zeros[i] = prefix_zeros[i - 1] + (s[i - 1] == '0' ? 1 : 0);
    }

    int best_diff_L = 0;
    int best_zeros_L = 0, best_ones_L = 0;
    int best_cost = min(total_ones, n - total_ones); // worst case - we swap all zeros or all ones

    for (int r = 0; r <= n; r++) {
        int zeros_inside = prefix_zeros[r] - best_zeros_L;
        int ones_outside = total_ones - (prefix_ones[r] - best_ones_L);
        int cand = zeros_inside + ones_outside;
        best_cost = min(best_cost, cand);

        int l = r;
        int current_diff = prefix_zeros[l] - prefix_ones[l]; // calculate and save max diff for L
        if (current_diff > best_diff_L) {
            best_diff_L = current_diff;
            best_zeros_L = prefix_zeros[l];
            best_ones_L = prefix_ones[l];
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