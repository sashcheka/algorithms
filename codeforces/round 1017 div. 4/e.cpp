#include<iostream>
#include<vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> bits (30, 0);
    for (int i = 0; i < n; i++) {
        for (int bit = 0; bit < 30; bit++) {
            if (a[i] & (1 << bit)) bits[bit]++;
        }
    }

    long long result = 0;
    for (int k = 0; k < n; k++) {
        long long current_xor = 0;
        for (int bit = 0; bit < 30; bit++) {
            if (a[k] & (1 << bit)) current_xor += (long long)(1 << bit) * (n - bits[bit]);
            else current_xor += (long long)(1 << bit) * bits[bit];
        }
        result = max(result, current_xor);
    }

    cout << result << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
