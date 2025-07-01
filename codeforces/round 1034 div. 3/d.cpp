#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ones = 0;
    for (char ch : s) if (ch == '1') ones++;

    if (ones <= k || 2*k > n) 
        cout << "Alice" << '\n';
    else 
        cout << "Bob" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
