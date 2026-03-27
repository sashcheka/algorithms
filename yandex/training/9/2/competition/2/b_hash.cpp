#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<int>> pos(26);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push_back(i);
        mx = max(mx, (int)pos[s[i] - 'a'].size());
    }

    const int base = 137;
    vector<ull> hash(n + 1);
    vector<ull> power(n + 1, 1);
    for (int i = 0; i < n; i++) {
        hash[i + 1] = hash[i] * base + s[i];
        power[i + 1] = power[i] * base;
    }

    auto get = [&](const int& l, const int& len) -> ull {
        return hash[l + len] - hash[l] * power[len];
    };

    int best = 1;
    for (int i = 0; i < 26; i++) {
        if (pos[i].size() != mx) continue;

        const vector<int>& p = pos[i];

        int l = 1;
        int r = n - p.back();
        for (int j = 1; j < p.size(); j++) {
            r = min(r, p[j] - p[j - 1]);
        }
        int cand = 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            bool ok = true;
            ull curr = get(p[0], m);

            for (int j : p) {
                if (curr != get(j, m)) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                cand = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        best = max(best, cand);
    }

    cout << best;
    return 0;
}
