#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    sort(h.begin(), h.end());
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(b.begin(), b.end());
    int i = 0;
    int j = 0;
    while (i < n && j < m && k > 0) {
        while (j < m && h[i] > b[j]) j++;
        if (j >= m) break;
        k--;
        i++;
        j++;
    }
    if (k == 0) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}