#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<pair<char, int>> v;
    for (int i = 0; i < n - 1; i++) {
        if (p[i] > p[i + 1]) {
            if (v.empty() || v.back().first == '<') v.push_back({'>', 1});
            else v.back().second++;
        } else {
            if (v.empty() || v.back().first == '>') v.push_back({'<', 1});
            else v.back().second++;
        }
    }

    long long ans = 0;
    for (int i = 1; i < v.size() - 1; i++) {
        if (v[i].first == '>') ans += (long long)v[i - 1].second * v[i + 1].second; 
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}