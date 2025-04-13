#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    m = n - m;
    while (m--) {
        if (l != 0) l++;
        else if (r != 0) r--;
    }

    cout << l << ' ' << r << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
