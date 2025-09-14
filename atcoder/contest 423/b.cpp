#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++) cin >> l[i];
    int lead = 0;
    while (lead < n && l[lead] == 0) lead++;
    int trail = 0;
    while (trail < n && l[n - 1 - trail] == 0) trail++;
    int ans = max(0, n + 1 - 2 - lead - trail);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}