#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long mn = a[0];
    long long mx = a[n - 1];

    long long cand_1 = mx;
    int l = 0;
    int r = n - 1;
    while (a[r] == cand_1) r--;
    if ((r - l + 1) % 2 == 0) {
        bool valid = true;
        while (l < r) {
            if (a[l] + a[r] != cand_1) {
                valid = false;
                break;
            }
            l++;
            r--;
        }
        if (valid) cout << cand_1 << ' ';
    }

    long long cand_2 = mn + mx;
    if (n % 2 == 0) {
        bool valid = true;
        for (int i = 0; i < n / 2; i++) {
            if (a[i] + a[n - i - 1] != cand_2) {
                valid = false;
                break;
            }
        }
        if (valid) cout << cand_2 << '\n';
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}