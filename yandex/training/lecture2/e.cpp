#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    
    int l, r;
    int m = n / 2;
    if (n % 2) {
        cout << v[m] << ' ';
        l = m - 1;
        r = m + 1;
    } else {
        l = m - 1;
        r = m;
    }

    bool turn_left = true;
    while (l >= 0 || r < n) {
        if (turn_left && l >= 0) {
            cout << v[l] << ' ';
            l--;
        } else if (!turn_left && r < n) {
            cout << v[r] << ' ';
            r++;
        }

        turn_left = !turn_left;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
