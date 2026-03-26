#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int max_cnt = 0;
    set<char> chars(s.begin(), s.end());

    for (char c : chars) {
        int cnt = count(s.begin(), s.end(), c);
        max_cnt = max(max_cnt, cnt);
    }

    int ans = 1;

    for (char c : chars) {
        if (count(s.begin(), s.end(), c) != max_cnt) continue;

        vector<int> p;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == c) p.push_back(i);
        }

        int cur = 1;
        while (true) {
            bool ok = true;
            for (int i : p) {
                if (i + cur >= (int)s.size() || s[i + cur] != s[p[0] + cur]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
            cur++;
        }

        ans = max(ans, cur);
    }

    cout << ans << endl;
    return 0;
}