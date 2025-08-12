#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> t[i];

    unordered_map<int, int> dupa;
    dupa.reserve(n);
    for (int i = 0; i < n; i++) {
        int rs = s[i] % k;
        dupa[min(rs, k - rs)]++;
        int rt = t[i] % k;
        dupa[min(rt, k - rt)]--;
    }

    for (auto& [val, cnt] : dupa) {
        if (cnt != 0) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
