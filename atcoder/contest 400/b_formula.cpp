#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    if (n == 1) {
        if (m + 1 <= 1e9) cout << m + 1;
        else cout << "inf";
        return;
    }

    long long sum = n * (pow(n, m) - 1) / (n - 1);
    if ((sum + 1) >= 0 && (sum + 1) <= 1e9) cout << (sum + 1);
    else cout << "inf";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}