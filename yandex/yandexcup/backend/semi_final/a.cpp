#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> rows(n);
    vector<int> cols(n);
    for (int i = 0; i < n; i++) cin >> rows[i] >> cols[i];

    sort(rows.begin(), rows.end());        
    sort(cols.begin(), cols.end());        

    long long dist = 0;
    for (int i = 0; i < n; i++) {
        dist += abs(rows[i] - i - 1);
        dist += abs(cols[i] - i - 1);
    }

    cout << dist; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
