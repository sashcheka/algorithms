#include<bits/stdc++.h>

using namespace std;

void solve() {
    long long n, a, b;
    cin >> n >> a >> b;

    long long integer = n / 3;
    long long reminder = n % 3;

    long long best = min({
        n * a,
        integer * b + reminder * a,
        (integer + 1) * b
    });

    cout << best << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
