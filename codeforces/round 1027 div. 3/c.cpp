#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int arrays = 1;
    int comp = a[0];
    for (int i = 1; i < n; i++) {
        if (comp + 1 < a[i]) {
            arrays++;
            comp = a[i];
        }
    }

    cout << arrays << '\n';
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
