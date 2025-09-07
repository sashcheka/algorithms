#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    vector<int> a(n);
    long long init_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        init_sum += a[i];
    }

    vector<int> cnt(n + 2, 0);
    for (int x : a) cnt[x]++;

    int M = 0;
    while (cnt[M] > 0) M++;

    int solo = 0;
    long long solo_sum = 0;
    for (int v = 0; v < M; v++) if (cnt[v] == 1) { solo++; solo_sum += v; }

    int diff = n - solo;
    if (diff == 0) {
        cout << init_sum << '\n';
        return;
    }

    int q = M;
    for (int v = 0; v < M; v++) {
        if (cnt[v] != 1) { q = v; break; }
    }

    long long ans;
    if (k == 1) {
        // after 1st op: unique < M stay as v; everything else becomes M
        ans = solo_sum + 1LL * diff * M;
    } else {
        // for k >= 2:
        long long small_sum = 1LL * q * (q - 1) / 2; // values 0..q-1, exactly once
        long long big_count = n - q;                 // equals diff, but based on q

        long long big;
        if (big_count == 1) {
            big = q;                                 // stabilizes
        } else if (q < M) {
            big = (k % 2 == 0) ? q : (q + 1);        // even -> q, odd -> q+1
        } else {
            big = (k % 2 == 0) ? (M + 1) : M;        // q == M case
        }

        ans = small_sum + big_count * big;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
