#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];

    if (t[0] > s) {
        cout << "No";
        return;
    }

    for (int i = 1; i < n; i++) {
        if (t[i] - t[i - 1] > s) {
            cout << "No";
            return;
        }
    }

    cout << "Yes";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}