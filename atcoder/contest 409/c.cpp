#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l;
    cin >> n >> l;

    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        int d;
        cin >> d;
        pos[i + 1] = (pos[i] + d) % l;
    }

    if (l % 3) {
        cout << 0;
        return;
    }

    int offset = l / 3;
    vector<int> cnt(l, 0);
    for (int i = 0; i < n; i++) cnt[pos[i]]++;

    long long ans = 0;
    for (int p = 0; p < l; p++) {
        int a = cnt[p];
        int b = cnt[(p + offset) % l];
        int c = cnt[(p + offset * 2) % l];
        ans += (long long)a * b * c;
    }

    cout << ans / 3;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}