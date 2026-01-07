#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, bool> dupa;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        dupa[a] = true;
    }
    int mex = 0;
    while (dupa[mex]) mex++;
    cout << min(mex, k - 1) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
