#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    int MAX = -1;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    unordered_map<int, int> dupa;
    for (int j = 0; j < m; j++) {
        vector<int> zeros;
        vector<int> ones;
        for (int i = 0; i < n; i++) {
            if (s[i][j] == '0') zeros.push_back(i+1);
            else ones.push_back(i+1);
        }

        if (zeros.size() == 0 || ones.size() == 0) {
            for (int k = 0; k < zeros.size(); k++) {
                dupa[zeros[k]]++;
                MAX = max(MAX, dupa[zeros[k]]);
            }
            for (int k = 0; k < ones.size(); k++) {
                dupa[ones[k]]++;
                MAX = max(MAX, dupa[ones[k]]);
            }
        } else if (zeros.size() < ones.size()) {
            for (int k = 0; k < zeros.size(); k++) {
                dupa[zeros[k]]++;
                MAX = max(MAX, dupa[zeros[k]]);
            }
        } else {
            for (int k = 0; k < ones.size(); k++) {
                dupa[ones[k]]++;
                MAX = max(MAX, dupa[ones[k]]);
            }
        }
    }

    vector<int> ans;
    for (auto [person, votes] : dupa) {
        if (votes == MAX) ans.push_back(person);
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}