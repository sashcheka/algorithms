#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    int a, b;
    unordered_map<int, int> mod_count;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        int MOD = (long long)(a + b) % n;
        mod_count[MOD]++;
    }

    long long total_pairs = (long long)m * (m - 1) / 2;
    long long parallel_pairs = 0;
    for (auto [MOD, count] : mod_count) {
        parallel_pairs += (long long)count * (count - 1) / 2;
    }

    cout << total_pairs - parallel_pairs;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}