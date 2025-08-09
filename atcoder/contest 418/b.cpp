#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    double ans = 0;

    for (int i = 0; i < n; i++) {
        int t_cnt = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == 't') {
                t_cnt++;
                if (s[i] == 't' && j - i + 1 >= 3) {
                    ans = max(ans, (double)(t_cnt-2) / (j-i+1-2));
                }
            }
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(17);
    solve();
    return 0;
}