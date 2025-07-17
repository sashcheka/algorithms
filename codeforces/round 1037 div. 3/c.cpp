#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    
    int water = 1;
    int curr_h = h[k-1];
    sort(h.begin(), h.end());

    int curr_idx = 0;
    for (int i = 0; i < n; i++) {
        if (curr_h == h[i]) {
            curr_idx = i;
            break;
        }
    }

    while (true) {
        if (curr_h == h[n - 1]) {
            cout << "YES" << '\n';
            return;
        }

        int next_h = h[++curr_idx];
        int time = next_h - curr_h;
        water += time;
        // cout << "bbug: " << curr_idx << ' ' << curr_h << ' ' << water << '\n';
        if (water > curr_h + 1) {
            cout << "NO" << '\n';
            return;
        }
        curr_h = next_h;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
