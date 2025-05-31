#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    long long xmin1 = LLONG_MAX, xmin2 = LLONG_MAX;
    long long xmax1 = LLONG_MIN, xmax2 = LLONG_MIN;
    int cnt_xmin1 = 0, cnt_xmax1 = 0;

    long long ymin1 = LLONG_MAX, ymin2 = LLONG_MAX;
    long long ymax1 = LLONG_MIN, ymax2 = LLONG_MIN;
    int cnt_ymin1 = 0, cnt_ymax1 = 0;

    for (auto &pt : p) {
        long long x = pt.first, y = pt.second;

        if (x < xmin1) { xmin2 = xmin1; xmin1 = x; cnt_xmin1 = 1; }
        else if (x == xmin1) { cnt_xmin1++; }
        else if (x < xmin2) { xmin2 = x; }

        if (x > xmax1) { xmax2 = xmax1; xmax1 = x; cnt_xmax1 = 1; }
        else if (x == xmax1) { cnt_xmax1++; }
        else if (x > xmax2) { xmax2 = x; }

        if (y < ymin1) { ymin2 = ymin1; ymin1 = y; cnt_ymin1 = 1; }
        else if (y == ymin1) { cnt_ymin1++; }
        else if (y < ymin2) { ymin2 = y; }

        if (y > ymax1) { ymax2 = ymax1; ymax1 = y; cnt_ymax1 = 1; }
        else if (y == ymax1) { cnt_ymax1++; }
        else if (y > ymax2) { ymax2 = y; }
    }

    long long w0 = xmax1 - xmin1 + 1;
    long long h0 = ymax1 - ymin1 + 1;
    long long ans = w0 * h0;

    for (auto &pt : p) {
        long long x = pt.first, y = pt.second;

        long long xlo = xmin1;
        if (x == xmin1 && cnt_xmin1 == 1) xlo = xmin2;

        long long xhi = xmax1;
        if (x == xmax1 && cnt_xmax1 == 1) xhi = xmax2;

        long long ylo = ymin1;
        if (y == ymin1 && cnt_ymin1 == 1) ylo = ymin2;

        long long yhi = ymax1;
        if (y == ymax1 && cnt_ymax1 == 1) yhi = ymax2;

        long long w = xhi - xlo + 1;
        long long h = yhi - ylo + 1;
        long long M = w * h;

        long long cost;
        if (n - 1 < M) {
            cost = M;
        } else {
            cost = min((w + 1) * h, w * (h + 1));
        }

        ans = min(ans, cost);
    }

    cout << ans << "\n";
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
