#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long rt, ct, ra, ca;
    cin >> rt >> ct >> ra >> ca;

    long long n;
    int m, l;
    cin >> n >> m >> l;

    vector<pair<char, int>> t(m);
    for (int i = 0; i < m; i++) {
        char d;
        int dl;
        cin >> d >> dl;
        t[i] = {d, dl};
    }

    vector<pair<char, int>> a(l);
    for (int i = 0; i < l; i++) {
        char d;
        int dl;
        cin >> d >> dl;
        a[i] = {d, dl};
    }

    long long ans = 0;
    int ti = 0;
    int ai = 0;
    unordered_map<char, pair<int, int>> dupa = {
        {'U', {-1, 0}},
        {'D', {+1, 0}},
        {'L', {0, -1}},
        {'R', {0, +1}}
    };

    while (ti < t.size() && ai < a.size()) {
        auto [t_d, t_l] = t[ti];
        auto [a_d, a_l] = a[ai];

        if (t_l < a_l) {
            a[ai].second -= t_l;
            ti++;
        } else if (t_l > a_l) {
            t[ti].second -= a_l;
            ai++;
        } else if (t_l == a_l) {
            ti++;
            ai++;
        }

        if (rt == ra && ct == ca && t_d == a_d) {
            ans += min(t_l, a_l);
        } else {
            long long d = abs(rt - ra) + abs(ct - ca);
            if (d != 0 && (d % 2 == 0)) {
                long long k = d / 2;
                if (k <= min(t_l, a_l)) {
                    auto [drt, dct] = dupa[t_d];
                    auto [dra, dca] = dupa[a_d];
                    long long nrt = rt + drt * k;
                    long long nct = ct + dct * k;
                    long long nra = ra + dra * k;
                    long long nca = ca + dca * k;
                    if (nrt == nra && nct == nca) ans++;
                }
            }
        }

        rt += (long long)dupa[t_d].first * min(t_l, a_l);
        ct += (long long)dupa[t_d].second * min(t_l, a_l);
        ra += (long long)dupa[a_d].first * min(t_l, a_l);
        ca += (long long)dupa[a_d].second * min(t_l, a_l);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}