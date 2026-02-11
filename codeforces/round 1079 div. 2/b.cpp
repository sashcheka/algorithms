#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    vector<int> a;
    a.reserve(n);
    unordered_set<int> setik;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        if (a.size() == 0 || a.back() != elem) {
            a.push_back(elem);
        } else if (setik.count(elem)) {
            cout << "No" << '\n';
            return;
        }
    }

    int i = 0;
    int j = 0;
    int m = (int)a.size();
    while (i < n && j < m) {
        while (i < n && p[i] != a[j]) i++;
        if (i < n && p[i] == a[j]) {
            i++;
            j++;
        }
    }

    if (j < m) cout << "No" << '\n';
    else cout << "Yes" << '\n';
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
