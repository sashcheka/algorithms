#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if ((n & (n - 1)) == 0) {
        cout << -1 << '\n';
        return;
    }
    int p = 3;
    vector<int> a(n);
    a[0] = (n % 2 ? n - 1 : n);
    for (int i = 1; i < n - 1; i++) {
        a[i] = p;
        if (p % 2) p--;
        else p += 3;
    }
    a[n - 1] = 1;
    if (n % 2 == 0) {
        int bit = 31;
        while (!(1 << bit & n)) bit--;
        int r = n - (1 << bit) - 1;
        swap(a[0], a[r]);
    }
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
