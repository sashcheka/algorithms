#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    long long init_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2 == 0) init_sum += a[i];
        else init_sum -= a[i];
    }

    if (n == 1) {
        cout << init_sum << '\n';
        return;
    }

    long long same_parity_diff = 0;
    if (n % 2 == 0) same_parity_diff = n - 2;
    else same_parity_diff = n - 1;

    long long min_even_l = LLONG_MAX;
    long long min_even_r = LLONG_MAX;
    long long max_odd_l = LLONG_MIN;
    long long max_odd_r = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            min_even_l = min(min_even_l, 2*a[i] - i);
            min_even_r = min(min_even_r, 2*a[i] + i);
        } else {
            max_odd_l = max(max_odd_l, 2*a[i] - i);
            max_odd_r = max(max_odd_r, 2*a[i] + i);
        }
    }

    long long swap_cand_1 = max_odd_l - min_even_l;
    long long swap_cand_2 = max_odd_r - min_even_r;
    long long gain = max({0LL, same_parity_diff, swap_cand_1, swap_cand_2});

    cout << init_sum + gain << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
