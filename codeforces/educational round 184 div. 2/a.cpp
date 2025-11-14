#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, a;
    cin >> n >> a;
    int less = 0;
    int more = 0;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        if (v < a) less++;
        else if (v > a) more++;
    }

    int b;
    if (less >= more) {
        b = a - 1;
    } else {
        b = a + 1;
    }

    cout << b << '\n';
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
