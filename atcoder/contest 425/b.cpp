#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> p(n, -1);
    unordered_set<int> setik;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != -1 && setik.count(a[i])) {
            cout << "No";
            return;
        }
        if (a[i] != -1) {
            setik.insert(a[i]);
            p[i] = a[i];
        }
    }

    cout << "Yes" << '\n';
    int j = 1;
    for (int i = 0; i < n; i++) {
        if (p[i] == -1) {
            while (setik.count(j)) {
                j++;
            }
            p[i] = j;
            j++;
        }
        cout << p[i] << ' ';
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}