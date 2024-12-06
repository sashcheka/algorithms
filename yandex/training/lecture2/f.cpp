#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    int a;
    long long s1 = 0, s2 = 0, s3 = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a;
        s1 = (s1 + a) % MOD;
        s2 = (s2 + 1LL * a * a % MOD) % MOD;
        s3 = (s3 + 1LL * a * a % MOD * a % MOD) % MOD;
    }

    long long product1 = 1LL * s1 * s1 % MOD * s1 % MOD;  // s1^3
    long long product2 = 3LL * s1 % MOD * s2 % MOD;       // 3 * s1 * s2
    long long product3 = 2 * s3 % MOD;                    // 2 * s3

    long long sum = (product1 - product2 + product3 + MOD) % MOD;

    sum = sum * 166666668 % MOD;

    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
