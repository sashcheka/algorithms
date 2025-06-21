#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> d[i];

    vector<int> p(n + 1);
    for (int i = 1; i < n + 1; i++) p[i] = p[i - 1] + d[i - 1];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << p[j] - p[i] << " \n"[j == n - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}