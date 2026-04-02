#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int cases;
    cin >> cases;

    for (int c = 0; c < cases; c++) {
        ll n, d;
        cin >> n >> d;
        ll best = n + 1;

        vector<pair<ll, ll>> row(n);
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; i++) {
            ll t, k;
            cin >> t >> k;
            row[i] = {t, k};
            prefix[i + 1] = prefix[i] + k;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (prefix[i] + d <= row[i].first) {
                best = min(best, (long long)i + 1);
            } else {
                break;
            }
        }

        cout << best << "\n";
    }

    return 0;
}