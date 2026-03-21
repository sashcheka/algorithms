#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    ll ans = LLONG_MAX;

    auto check = [&](ll rows) {
        ll rem = n % rows;
        ll max_row = n / rows + (rem > 0);

        if (rem == 0) {
            ans = min(ans, llabs(rows - max_row));
            return;
        }

        if (llabs(2 * rem - rows) <= 1) {
            ans = min(ans, llabs(rows - max_row));
        }
    };

    auto go = [&](ll students) {
        for (ll rows = 1; rows * rows <= students; rows++) {
            if (students % rows == 0) {
                check(rows);
                check(students / rows);
            }
        }
    };

    go(n);
    go(2 * n - 1);
    go(2 * n);
    go(2 * n + 1);

    cout << ans;
    return 0;
}