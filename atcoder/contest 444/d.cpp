#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int mx = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    vector<int> sweep(mx + 1);
    for (int i = 0; i < n; i++) {
        sweep[0] += 1;
        sweep[a[i]] -= 1;
    }

    vector<int> digits(mx + 5);
    int run = 0;
    int carry = 0;
    for (int i = 0; i < mx + 5 || carry > 0; i++) {
        if (i < mx + 1) run += sweep[i];
        int digit = (run + carry) % 10;
        digits[i] = digit;
        carry = (run + carry) / 10;
    }

    bool passed_lead_zeroes = false;
    for (int i = mx + 4; i >= 0; i--) {
        if (digits[i] != 0) passed_lead_zeroes = true;
        if (passed_lead_zeroes) cout << digits[i];
    }

    cout << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}