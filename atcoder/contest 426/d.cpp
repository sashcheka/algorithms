#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int zeros = 0;
    int ones = 0;
    for (char ch : s) {
        if (ch == '0') zeros++;
        else ones++;
    }

    int max_zeros = 0, max_ones = 0;
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && s[j] == s[i]) j++;
        int len = j - i;
        if (s[i] == '0') max_zeros = max(max_zeros, len);
        else max_ones = max(max_ones, len);
        i = j;
    }

    int to_zeros = ones + 2 * (zeros - max_zeros);
    int to_ones  = zeros + 2 * (ones - max_ones);

    cout << min(to_zeros, to_ones) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}