#include <iostream>

using namespace std;

long long countPrefix(long long m, int rem) {
    if (m < rem) return 0;
    return (m - rem) / 4 + 1;
}

long long countRange(long long l, long long r, int rem) {
    if (l > r) return 0;
    return countPrefix(r, rem) - countPrefix(l - 1, rem);
}

void solve() {
    long long n, x;
    cin >> n >> x;

    const long long MOD = 998244353;

    long long cl0 = (1 + countRange(1, x - 1, 3)) % MOD;
    long long cr0 = countRange(x, n, 3) % MOD;

    long long cl1 = countRange(0, x - 1, 1) % MOD;
    long long cr1 = countRange(x, n, 1) % MOD;

    long long ans = (cl0 * cr0 % MOD + cl1 * cr1 % MOD) % MOD;
    cout << ans << "\n";

    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
