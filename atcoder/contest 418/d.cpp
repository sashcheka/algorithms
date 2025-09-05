#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    int n;
    string t;
    cin >> n >> t;

    long long ans = 0;
    vector<int> cnt = {1, 0};
    bool parity = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == '0') parity = !parity;
        ans += cnt[parity];
        cnt[parity]++;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}