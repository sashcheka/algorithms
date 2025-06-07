#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cand = i + 1;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] >= cand) cnt++;
        }
        if (cnt >= cand) ans = max(ans, cand);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}