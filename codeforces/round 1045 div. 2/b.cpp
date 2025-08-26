#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> b(n);
    if (k % 2) {
        for (int i = 0; i < n; i++) {
            if (a[i] % 2) b[i] = a[i] + k;
            else b[i] = a[i];
        }
    } else {
        for (int i = 0; i < n; ++i) {
            long long r = a[i] % (k + 1);
            b[i] = a[i] + k * r;
        }
    }

    for (int i = 0; i < n; i++) cout << b[i] << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
