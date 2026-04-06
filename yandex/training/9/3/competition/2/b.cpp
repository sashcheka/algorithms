#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int cases;
    cin >> cases;

    for (int c = 0; c < cases; c++) {
        ll n, d;
        cin >> n >> d;
        ll ans = 0;
        ll run = 0;
        
        for (int i = 0; i < n; i++) {
            ll t, k;
            cin >> t >> k;
            if (t < run + d) ans = i + 1;
            run += k;
        }

        cout << ans + 1 << "\n";
    }

    return 0;
}