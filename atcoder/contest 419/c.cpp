#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long min_x = LLONG_MAX;
    long long max_x = LLONG_MIN;
    long long min_y = LLONG_MAX;
    long long max_y = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        long long r, c;
        cin >> r >> c;
        min_x = min(min_x, c);
        max_x = max(max_x, c);
        min_y = min(min_y, r);
        max_y = max(max_y, r);
    }

    long long mid_x = (max_x + min_x) / 2LL;
    long long mid_y = (max_y + min_y) / 2LL;
    long long diff = max({max_x - mid_x, max_y - mid_y, mid_x - min_x, mid_y - min_y});
    cout << diff;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}