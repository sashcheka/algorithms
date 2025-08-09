#include <bits/stdc++.h>
using namespace std;

int bs(vector<int>& a, int& b) {
    int l = 0;
    int r = (int)a.size() - 1;

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] < b) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return l;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<long long> p(n+1, 0);
    for (int i = 1; i < n+1; i++) p[i] = p[i-1] + a[i-1];

    for (int i = 0; i < q; i++) {
        int b;
        cin >> b;

        if (b > a.back()) {
            cout << -1 << '\n';
            continue;
        }

        int idx = bs(a, b);
        long long x = p[idx] + (long long)(n-idx)*(b-1) + 1;
        cout << x<< '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}