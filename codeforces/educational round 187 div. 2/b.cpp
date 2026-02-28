#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = (int)s.size();
    int sum = 0;
    vector<int> a(n);
    for (int i = n - 1; i >= 0; --i) {
        int d = s[i] - '0';
        sum += d;
        a[i] = d;
    }
    --a[0];
    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;
    int i = 0;
    while (sum >= 10) {
        sum -= a[i++];
        ans++;
    }
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
