#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll countNumbers(ll mid, ll lcm_ab, ll lcm_ac, ll lcm_bc, ll lcm_abc) {
    return (mid / lcm_ab + mid / lcm_ac + mid / lcm_bc) - 3 * (mid / lcm_abc);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll a, b, c, n;
    cin >> a >> b >> c >> n;

    ll lcm_ab = lcm(a, b);
    ll lcm_ac = lcm(a, c);
    ll lcm_bc = lcm(b, c);
    ll lcm_abc = lcm(lcm_ab, c);

    ll left = 1, right = 1e18, ans = -1;
    while(left <= right) {
        ll mid = left + (right - left) / 2;
        ll cnt = countNumbers(mid, lcm_ab, lcm_ac, lcm_bc, lcm_abc);

        if(cnt < n) {
            left = mid + 1;
        } else {
            ans = mid;
            right = mid - 1;
        }
    }

    if(ans > 1e18 || ans == -1)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}
