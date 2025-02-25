#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> res;
    int current_or = 0;

    for (int i = 0; i < n; i++) {
        if ((i | x) == x) {
            res.push_back(i);
            current_or |= i;
        } else {
            res.push_back(0);
        }
    }

    if (current_or != x) res[n - 1] = x;

    for (int num : res) cout << num << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
