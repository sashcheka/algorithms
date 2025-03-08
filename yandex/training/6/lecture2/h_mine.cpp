#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<long long> prefix(n, 0);
    vector<long long> sufix(n, 0);

    for (int i = 1; i < n; i++) {
        long long sum = 0;
        for (int j = 0; j <= i; j++) {
            prefix[i] += v[j] * (i - j);
        }
    }
    
    for (int i = n - 2; i >= 0; i--) {
        long long sum = 0;
        for (int j = n - 1; j >= i; j--) {
            sufix[i] += v[j] * (j - i);
        }
    };

    // for (int i = 0; i < n; i++) cout << prefix[i] << " \n"[i == n - 1];
    // for (int i = 0; i < n; i++) cout << sufix[i] << " \n"[i == n - 1];

    long long cand = LLONG_MAX;
    for (int i = 0; i < n; i++) cand = min(cand, prefix[i] + sufix[i]);
    cout << cand;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
