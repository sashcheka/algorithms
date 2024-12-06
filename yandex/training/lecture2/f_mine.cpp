#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    int a;
    int p = 3;
    vector<long long> v(p + 1, 0);
    v[0] = 1;
    
    for (int i = 0; i < n; i++) {
        cin >> a;

        for (int j = p; j > 0 ; j--) v[j] = (v[j] + v[j - 1] * a) % MOD;

        // st = (st + sp * a) % MOD;
        // sp = (sp + s * a) % MOD;
        // s = (s + a) % MOD;
    }

    cout << v[p];
    cout.flush();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
