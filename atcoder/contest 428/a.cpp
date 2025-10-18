#include <bits/stdc++.h>
using namespace std;

void solve() {
    int s, a, b, x;
    cin >> s >> a >> b >> x;
    int dist = 0;
    while (x) {
        dist += s * min(a, x);
        x -= min(a, x);
        x -= min(b, x);
    }
    cout << dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}