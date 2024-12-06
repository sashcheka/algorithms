#include<bits/stdc++.h>
 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    string s, t;
    cin >> s >> t;

    int idx = 0;
    int n = min(s.length(), t.length());
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            idx = i + 1;
            break;
        }
    }

    if (idx == 0) {
        if (s.length() < t.length())
            idx = s.length() + 1;
        else if (s.length() > t.length())
            idx = t.length() + 1;
    }

    cout << idx;

    return 0;
}