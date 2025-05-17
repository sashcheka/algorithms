#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    __int128 res = 1;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;

        res *= a;
        __int128 temp = res;
        int digits = 0;
        while (temp) {
            temp /= 10;
            digits++;
        }

        if (digits > k) res = 1;
    }

    cout << (long long)res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}