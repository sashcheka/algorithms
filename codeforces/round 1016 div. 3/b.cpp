#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    bool seen_not_zero = false;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != '0') seen_not_zero = true;
        else if (seen_not_zero) n--;
    }
    
    cout << n - 1 << '\n';
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
