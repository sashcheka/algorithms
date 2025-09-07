#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> b(n);
    unordered_map<int, int> dupa;
    for (int i = 0; i < n; i++) {
        cin >> b[i].first;
        b[i].second = i;
        dupa[b[i].first]++;
    }

    for (auto& [val, cnt] : dupa) {
        if (cnt % val != 0) {
            cout << -1 << '\n';
            return;
        }
    }

    sort(b.begin(), b.end());

    int cand = 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        auto [val, idx] = b[i];
        a[idx] = cand;
        dupa[val]--;
        if (dupa[val] % val == 0) cand++;
    }
    
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
