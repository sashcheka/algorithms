#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll p, v;
    cin >> p >> v;
    ll q, m;
    cin >> q >> m;

    ll minV = p - v;
    ll maxV = p + v;
    ll minM = q - m;
    ll maxM = q + m;

    ll ans;
    if (maxV < minM || maxM < minV) {
        ans = (maxV - minV + 1) + (maxM - minM + 1);
    } else {
        ans = max(maxV, maxM) - min(minV, minM) + 1;
    }

    cout << ans << "\n";

    return 0;
}