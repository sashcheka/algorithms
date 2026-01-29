#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int zeroes = 0;
    int ans = 0;
    for (char ch : s) {
        if (ch == '0') zeroes++;
        else ans++;
    }
    if (zeroes == n) {
        cout << (zeroes + 2) / 3 << '\n';
        return;
    }

    int i = 0;
    while (s[i] != '1') i++;
    int l = i;
    ans += (l + 1) / 3;

    i = n - 1;
    while (s[i] != '1') i--;
    int r = i;
    ans += (n - 1 - r + 1) / 3;

    int prev_one = -1;
    for (int i = l; i <= r; i++) {
        if (s[i] == '1') {
            if (prev_one != -1) {
                int length = i - prev_one - 1;
                ans += length / 3;
            }
            prev_one = i;
        }
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
