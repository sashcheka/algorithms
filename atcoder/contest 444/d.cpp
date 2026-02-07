#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    vector<long long> diff(mx + 2, 0);
    for (int x : a) {
        diff[0] += 1;
        diff[x] -= 1;
    }

    vector<int> digits;
    long long curr = 0;
    long long carry = 0;
    for (int p = 0; p < mx; p++) {
        curr += diff[p];
        long long val = curr + carry;
        digits.push_back((int)(val % 10));
        carry = val / 10;
    }
    while (carry > 0) {
        digits.push_back((int)(carry % 10));
        carry /= 10;
    }

    int dsize = digits.size();
    for (int i = dsize - 1; i >= 0; i--) cout << digits[i];
    cout << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
