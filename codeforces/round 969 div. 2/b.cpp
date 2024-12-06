#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m) {
    vector<long long> a(n);
    long long mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    
    for (int i = 0; i < m; i++) {
        char sign;
        int l, r;
        cin >> sign >> l >> r;

        if (sign == '+') {
            if (mx >= l && mx <= r)
                mx++;
        } else {
            if (mx >= l && mx <= r)
                mx--;
        }

        cout << mx << " ";
    }

    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        solve(n, m);
    }

    return 0;
}
