#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;

    unordered_set<char> setik;
    for (const char& ch : s) setik.insert(ch);

    int count = 0;
    for (const char& ch : t) {
        if (setik.count(ch)) {
            count++;
        }
    }
    
    cout << count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}
