#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b; 
    cin >> a >> b;

    long long ans = -1;
    if (b % 2 == 1) {
        if (a & 1) ans = a * b + 1;
    } else if (b % 4 == 2) {
        if ((a & 1) == 0) {
            long long m = b / 2;
            ans = max(a + b, a * m + 2);
        }
    } else if (b % 4 == 0) {
        long long m = b / 2;
        long long cand_1 = a * 2 + m;
        long long cand_2 = a * m + 2;
        ans = max(cand_1, cand_2);
        if (a % 2 == 0) ans = max(ans, a + b);
    }

    cout << ans << '\n'; 
  }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
