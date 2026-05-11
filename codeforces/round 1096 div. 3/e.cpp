#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    long long total_moved = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_moved += a[i];
    }

    vector<int> min_suffix_remains(n);
    min_suffix_remains[n - 1] = a[n - 1];
    total_moved -= min_suffix_remains[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        min_suffix_remains[i] = min(a[i], min_suffix_remains[i + 1]);
        total_moved -= min_suffix_remains[i];
    }

    int best = 1;
    int curr = 1;
    for (int i = 1; i < n; i++) {
        if (min_suffix_remains[i - 1] == min_suffix_remains[i]) {
            curr++;
        } else {
            best = max(best, curr);
            curr = 1;
        }
    }
    best = max(best, curr);

    cout << total_moved + (best - 1) << "\n";
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
