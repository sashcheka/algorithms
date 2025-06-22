#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> type(q);
    vector<int> p(q);
    vector<string> s(q);
    for (int i = 0; i < q; i++) {
        cin >> type[i];
        cin >> p[i];
        if (type[i] == 2) {
            cin >> s[i];
            reverse(s[i].begin(), s[i].end());
        }
    }

    string ans = "";
    int i = 0; // server id = 0
    for (int t = q - i; t >= 0; t--) {
        if (type[t] == 1) {
            if (i == p[t]) i = 0;
        } else if (type[t] == 2) {
            if (i == p[t]) ans += s[t];
        } else if (type[t] == 3) {
            if (i == 0) i = p[t];
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}