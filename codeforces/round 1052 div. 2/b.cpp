#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<unordered_set<int>> v(n);
    vector<int> dupa(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++) {
            int s;
            cin >> s;
            v[i].insert(s);
            dupa[s]++;
        }
    }

    for (int i = 1; i < m + 1; i++) {
        if (dupa[i] == 0) {
            cout << "NO" << '\n';
            return;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int s : v[i]) {
            if (dupa[s] == 1) {
                flag = false;
                break;
            }
        }

        if (flag) {
            ans++;
        }

        if (ans == 2) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
