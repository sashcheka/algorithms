#include <bits/stdc++.h>
using namespace std;

const int MAX_POWER = 11;

int get_digits_count(long long x) {
    int d = 0;
    while (x) {
        x /= 10;
        d++;
    }
    return max(d, 1);
};

void solve() {
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> powers(MAX_POWER);
    powers[0] = 1 % m;
    for (int d = 1; d < MAX_POWER; d++) powers[d] = (powers[d - 1] * 10) % m;

    vector<unordered_map<long long, long long>> count(MAX_POWER);
    for (int i = 0; i < n; i++) {
        long long mod_ai = a[i] % m;
        for (int d = 1; d < MAX_POWER; d++) {
            long long r = (mod_ai * powers[d]) % m;
            count[d][r]++;
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int d = get_digits_count(a[i]);
        long long need = (m - (a[i] % m)) % m;
        if (count[d].count(need)) ans += count[d][need];
    }

    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}