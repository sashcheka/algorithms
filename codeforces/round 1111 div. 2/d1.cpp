#include "../headers.h"

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> p(n);  // value, index
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }

    int best = 0;
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        int j = p[i].second;
        if (i == j) continue;

        int x = i ^ j;
        for (int exp = 31; exp >= 0; exp--) {
            int cand = 1 << exp;
            if (x & cand) {
                best = max(best, cand);
            }
        }
    }

    cout << best << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
