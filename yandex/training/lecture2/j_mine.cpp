#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int m, k;
    cin >> m >> k;
    vector<int> x(m);
    for (int i = 0; i < m; i++) cin >> x[i];

    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) p[i] += p[i - 1] + (a[i - 1] == a[i]);

    vector<int> is(n, 0);
    for (int i = 1; i < n; i++) {
        if (a[i - 1] <= a[i]) {
            is[i] = is[i - 1] + 1;
        } else {
            is[i] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int idx = x[i] - 1;

        if (is[idx] == 0) {
            cout << idx + 1 << ' ';
            continue;
        }

        int l = idx - is[idx];
        int goal = p[idx] - k;
        int stop = lower_bound(p.begin() + l, p.begin() + idx + 1, goal) - p.begin();

        cout << stop + 1 << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
