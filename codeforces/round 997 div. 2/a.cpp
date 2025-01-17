#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    int x_init, y_init;
    cin >> x_init >> y_init;
    int x_start = x_init;
    int y_start = y_init;

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x_init += x;
        y_init += y;
    }        

    int x_finish = x_init;
    int y_finish = y_init;

    int p = (x_finish + m - x_start) * 2 + (y_finish + m - y_start) * 2;
    cout << p << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
