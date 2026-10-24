#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <climits>

using namespace std;

constexpr int MOD = 998244353;

void solve() {
    long long l, r;
    cin >> l >> r;

    long long sum = 0;
    for (long long t = l; t <= r; ++t) {
        if (t <= 1) {
            sum = (sum + t) % MOD;
            continue;
        }

        long long rem = t / 2;
        long long cost = 0;
        long long best = LLONG_MAX;

        for (int b = 59; b >= 1; --b) {
            long long val = (1ll << b) - 1;
            long long cnt = rem / val;
            long long left = rem % val;

            long long cand = cost + (cnt + 1) * (b + 2)
                + 2 * (val - left);

            best = min(best, cand);

            cost += cnt * (b + 2);
            rem = left;
        }

        best = min(best, cost);
        best -= t % 2;

        sum = (sum + best) % MOD;
    }

    cout << sum << "\n";

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
