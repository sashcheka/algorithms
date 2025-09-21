#include<bits/stdc++.h>
using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;

    int n = r - l + 1;
    long long ans = 0;
    vector<int> a(n, -1);
    for (int i = r; i >= l; i--) {
        if (a[i] != -1) {
            ans += a[i] | i;
            continue;
        }

        int val = 0;
        int bit = 0;
        int temp = i;
        while (temp) {
            if (!(temp & 1)) {
                val += (1 << bit);
            }
            temp >>= 1;
            bit++;
        }
        a[i] = val;
        a[val] = i;
        ans += val | i;
    }

    cout << ans << '\n';
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
