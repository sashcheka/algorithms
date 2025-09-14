#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, r;
    cin >> n >> r;
    
    vector<int> l(n);
    for (int i = 0; i < n; i++) cin >> l[i];
    
    int lead = 0;
    while (lead < n && l[lead] == 1) lead++;
    
    int trail = n - 1;
    while (trail >= 0 && l[trail] == 1) trail--;

    long long ans = 0;
    for (int i = min(lead, r); i < max(trail + 1, r); i++) {
        if (l[i] == 0) ans += 1;
        else ans += 2;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}