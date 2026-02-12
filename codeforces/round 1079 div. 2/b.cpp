#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        pos[p] = i;
    }

    bool valid = true;
    int most_left_idx = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (pos[a] < most_left_idx) {
            valid = false;
            continue;
        }
        most_left_idx = pos[a];
    }

    cout << (valid ? "Yes" : "No") << "\n";
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
