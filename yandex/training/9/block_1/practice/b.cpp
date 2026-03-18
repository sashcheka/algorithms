#include<bits/stdc++.h>

using namespace std;

using ll = long long;

pair<ll, ll> get_cand(const ll& k, const ll& m, const ll& x) {
    ll total = m * x;
    ll p = (k + total - 1) / total;
    ll flat_num = (k - 1) % total + 1;
    ll n = (flat_num + x - 1) / x;
    return {p, n};
}

int main() {
    ll k1, m, k2, p2, n2;
    cin >> k1 >> m >> k2 >> p2 >> n2;

    ll p1 = -1;
    ll n1 = -1;
    bool valid = false;
    const ll LIMIT = 1e6;

    for (ll x = 1; x <= LIMIT; x++) {
        auto [cand_p2, cand_n2] = get_cand(k2, m, x);
        if (p2 == cand_p2 && n2 == cand_n2) {
            auto [cand_p1, cand_n1] = get_cand(k1, m, x);
            if (!valid) {
                p1 = cand_p1;
                n1 = cand_n1;
                valid = true;
            } else {
                p1 = (p1 == cand_p1) ? p1 : 0;
                n1 = (n1 == cand_n1) ? n1 : 0;
            }
        }
    }

    if (valid) {
        cout << p1 << " " << n1 << "\n";
    } else {
        cout << "-1 -1" << "\n";
    }

    return 0;
}