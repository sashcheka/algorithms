#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<int>> pos(26);
    for (int i = 0; i < n; i++) pos[s[i] - 'a'].push_back(i);

    int mx = 0;
    for (int c = 0; c < 26; c++) mx = max(mx, (int)pos[c].size());

    const ull B = 239017;
    vector<ull> h(n + 1), p(n + 1, 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = h[i] * B + s[i];
        p[i + 1] = p[i] * B;
    }

    auto get = [&](int l, int len) {
        return h[l + len] - h[l] * p[len];
    };

    int ans = 1;

    for (int c = 0; c < 26; c++) {
        if ((int)pos[c].size() != mx) continue;

        auto &v = pos[c];
        int lim = n - v.back();

        for (int i = 0; i + 1 < (int)v.size(); i++)
            lim = min(lim, v[i + 1] - v[i]);

        int l = 1, r = lim, best = 1;
        while (l <= r) {
            int m = (l + r) / 2;
            ull cur = get(v[0], m);
            bool ok = true;

            for (int i = 1; i < (int)v.size(); i++) {
                if (get(v[i], m) != cur) {
                    ok = false;
                    break;
                }
            }

            if (ok) best = m, l = m + 1;
            else r = m - 1;
        }

        ans = max(ans, best);
    }

    cout << ans;
    return 0;
}