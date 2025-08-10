#include<bits/stdc++.h>
using namespace std;

long long f(int num, int k) {
    num %= k;
    if (num == 0) return 0;
    return min(num, abs(num - k));
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> t[i];

    unordered_map<long long, long long> bs, bt;
    for (int i = 0; i < n; i++) {
        bs[f(s[i], k)]++;
        bt[f(t[i], k)]++;
    }

    cout << (bs == bt ? "Yes" : "No") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
