#include<bits/stdc++.h>

using namespace std;

int bs(int& n, int& m, int& k) {
    int l = 1;
    int r = m;

    while (l <= r) {
        int b = l + (r - l) / 2;

        long long benches_per_row = (long long)(m / (b + 1)) * b + m % (b + 1);
        long long total_benches = benches_per_row * n;

        if (total_benches >= (long long)k) r = b - 1;
        else l = b + 1;
    }

    return l;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int result = bs(n, m, k);
    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
