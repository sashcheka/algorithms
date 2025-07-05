#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    queue<pair<int, int>> a; // count, value
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int c, x;
            cin >> c >> x;
            a.push({c, x});
        } else if (type == 2) {
            int k;
            cin >> k;
            long long sum = 0;
            while (k) {
                auto& f = a.front();
                sum += (long long)min(k, f.first)*f.second;
                int temp = f.first;
                f.first -= min(k, f.first);
                if (f.first == 0) a.pop();
                k -= min(k, temp);
            }
            cout << sum << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}