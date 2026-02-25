#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long x;
    cin >> x;
    vector<int> digits;
    digits.reserve(19);
    long long temp = x;
    int f1 = 0;
    while (temp) {
        int digit = temp % 10;
        f1 += digit;
        digits.push_back(digit);
        temp /= 10;
    }
    int first = digits.back();
    digits.pop_back();
    digits.push_back(first - 1);

    temp = f1;
    int f2 = 0;
    while (temp) {
        int digit = temp % 10;
        f2 += digit;
        temp /= 10;
    }

    if (f1 == f2) {
        cout << 0 << '\n';
        return;
    }

    sort(digits.rbegin(), digits.rend());
    int i = 0;
    int ans = 0;
    while (f1 >= 10) {
        f1 -= min(f1 - 9, digits[i]);
        ans++;
        i++;
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
