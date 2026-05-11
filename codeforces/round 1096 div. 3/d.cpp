#include<bits/stdc++.h>

using namespace std;

int check(int l, int r, const vector<int>& a, int n) {
    set<int> setik;
    for (int i = 0; i <= n; i++) {
        setik.insert(i);
    }

    while (l >= 0 && r < n * 2 && a[l] == a[r]) {
        setik.erase(a[l]);
        l--;
        r++;
    }

    return *setik.begin();
}

void solve() {
    int n;
    cin >> n;

    int fz = -1;
    int sz = -1;
    vector<int> a(n * 2);
    for (int i = 0; i < n * 2; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            if (fz == -1) fz = i;
            else sz = i;
        }
    }

    int best = max({check(fz, fz, a, n), check(sz, sz, a, n), check((fz + sz) / 2, (fz + sz + 1) / 2, a, n)});
    cout << best << "\n";

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
