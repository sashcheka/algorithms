#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> p(n + 1, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1];

    for (int i = 1; i <= n; i++)
        cout << p[i] << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}