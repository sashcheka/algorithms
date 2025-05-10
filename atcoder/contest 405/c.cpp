#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    long long s = 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        s -= a[i];
        ans += s * a[i];
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}