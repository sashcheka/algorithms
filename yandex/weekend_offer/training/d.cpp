#include<bits/stdc++.h>

using namespace std;

void go(int l, int r, int& n, string curr) {
    if (l == r && r == n) {
        cout << curr << '\n';
        return;
    }

    if (l < n) go(l + 1, r, n, curr + '(');

    if (r < l) go(l, r + 1, n, curr + ')');
}

void solve() {
    int n;
    cin >> n;
    go(0, 0, n, "");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}
