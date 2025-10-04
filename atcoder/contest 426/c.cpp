#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> count(n + 1, 1);
    
    set<int> setik;
    for (int i = 1; i <= n; i++) setik.insert(i);

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        int updated = 0;
        while (x >= *setik.begin()) {
            updated += count[*setik.begin()];
            setik.erase(setik.begin());
        }
        count[y] += updated;
        cout << updated << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}