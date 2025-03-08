#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
        
    int l = 0;
    int days = 0;
    for (int r = 0; r < n; r++) {
        while (v[r] - v[l] > k)
            l++;

        days = max(days, r - l);
    }

    cout << days + 1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
