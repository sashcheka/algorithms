#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int l = 1;
    int r = n;
    bool r_turn = true;
    vector<int> p(n);
    for (int i = n - 1; i >= 0; i--) {
        if (r_turn) {
            p[i] = r;
            r--;
        } else {
            p[i] = l;
            l++;
        }
        r_turn = !r_turn;
    }
    for (int i = 0; i < n; i++) {
        cout << p[i] << " \n"[i == n - 1];
    }
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
