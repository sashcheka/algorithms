#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string top, bottom;
    cin >> top >> bottom;

    int prev2 = 0;
    int prev1 = top[0] != bottom[0];

    for (int i = 1; i < n; i++) {
        int vCost = prev1 + (top[i] != bottom[i]);
        int hCost = prev2 + (top[i - 1] != top[i]) + (bottom[i - 1] != bottom[i]);
        int best = min(vCost, hCost);
        prev2 = prev1;
        prev1 = best;
    }

    cout << prev1 << "\n";

    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
