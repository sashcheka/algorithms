#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (k - 1 > n - k) k = n - k + 1;
    int l = 0;
    int r = 0;
    while (true) {
        if (l < k - 1 && (l + 1 + r + max(l + 1, r) - 1) <= m) l++;
        if (r < n - k && (l + r + 1 + max(l, r + 1) - 1) <= m) r++;
        else break;
    }
    cout << l + r + 1 << '\n';
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
