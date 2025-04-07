#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    long long sum = 1;
    long long term = 1;

    for (int i = 1; i <= m; i++) {
        term *= n;
        if (term > 1e9 || sum > 1e9 - term) {
            cout << "inf" << endl;
            return;
        }
        sum += term;
    }

    cout << sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}