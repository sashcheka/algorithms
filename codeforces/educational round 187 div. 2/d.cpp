#include<bits/stdc++.h>
using namespace std;

void solve() {
    size_t n, m;
    cin >> n >> m;
    size_t MAX = n + m;
    vector<int> cnt_x(MAX + 1);
    for (size_t i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt_x[x]++;
    }
    vector<int> div_y(MAX + 1);
    for (size_t i = 1; i <= MAX; i++) {
        if (cnt_x[i] == 0) continue;
        for (size_t j = i; j <= MAX; j += i) {
            div_y[j] += cnt_x[i];
        }
    }
    int alice = 0;
    int bob = 0;
    int both = 0;
    for (size_t i = 0; i < m; i++) {
        int y;
        cin >> y;
        if (div_y[y] == 0) {
            bob++;
        } else if (div_y[y] == n) {
            alice++;
        } else {
            both++;
        }
    }
    if (alice > bob) {
        cout << "Alice" << "\n";
    } else if (alice < bob) {
        cout << "Bob" << "\n";
    } else {
        cout << (both % 2 ? "Alice" : "Bob") << "\n";
    }
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
