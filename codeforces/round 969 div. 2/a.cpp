#include<bits/stdc++.h>
 
using namespace std;
 
void solve(int l, int r) {
    int f_odd, l_odd;

    if (l % 2)
        f_odd = l;
    else
        f_odd = ++l;

    if (r % 2)
        l_odd = r;
    else
        l_odd = --r;

    cout << ((l_odd - f_odd) / 2 + 1) / 2 << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        solve(l, r);
    }

    return 0;
}