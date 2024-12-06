#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    
    vector<int> v(26, 0);
    for (const char& ch : s) v[ch - 'a']++;
    for (const char& ch : t) v[ch - 'a']--;

    for (const int& i : v) {
        if (i != 0) {
            cout << 0;
            return;
        }
    }
    cout << 1;
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}
