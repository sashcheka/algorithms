#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    ll best = LLONG_MAX;
    for (ll r = 1; r * r <= 2 * n + 1; r++) {
        if (n % r == 0) {
            ll c = n / r;
            ll cand = abs(r - c);
            best = min(best, cand);
        } else if ((n + n) % r == 0) {
            ll c = (n + n) / r;
            ll cand = abs(r - (c + 1) / 2);
            best = min(best, cand);
        } else if ((n + n + 1) % r == 0) {
            ll c = (n + n + 1) / r;
            ll cand = abs(r - (c + 1) / 2);
            best = min(best, cand);
        } else if ((n + n - 1) % r == 0) {
            ll c = (n + n - 1) / r;
            ll cand = abs(r - (c + 1) / 2);
            best = min(best, cand);
        }
    }

    cout << best;
    return 0;
}