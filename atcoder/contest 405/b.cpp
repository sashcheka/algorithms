#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> setik(101, false);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (setik[a] == false) {
            setik[a] = true;
            m--;
        }

        if (m == 0) {
            cout << n - i;
            return;
        }
    }

    cout << 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}