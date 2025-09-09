#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int zeros = 0;
    int ones = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') zeros++;
        else ones++;
    }

    int to_shift = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && i >= zeros) to_shift++;
    }

    cout << to_shift << '\n';
}   

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
