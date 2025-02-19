#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    a[0] = min(a[0], b[0] - a[0]);
    for (int i = 1; i < n; i++) {
        int cand1 = a[i];
        int cand2 = b[0] - a[i];

        int diff1 = cand1 - a[i - 1];
        int diff2 = cand2 - a[i - 1];

        if (diff1 < 0 && diff2 < 0) {
            cout << "NO" << '\n';
            return;
        } else if (diff1 >= 0 && diff2 < 0) {
            a[i] = cand1;
        } else if (diff1 < 0 && diff2 >= 0) {
            a[i] = cand2;
        } else if (diff1 >= 0 && diff2 >= 0) {
            if (diff1 < diff2) {
                a[i] = cand1;
            } else {
                a[i] = cand2;
            }
        }
    }

    cout << "YES" << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
