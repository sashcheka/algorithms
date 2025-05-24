#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    int total = 36;

    int sum = 0;
    int diff = 0;

    set<pair<int, int>> setik;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if ((i + j) >= x) setik.insert({i, j});
            if (abs(i - j) >= y) setik.insert({i, j});
        }
    }

    double ans = (double)setik.size() / total;
    cout << setprecision(12) << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}