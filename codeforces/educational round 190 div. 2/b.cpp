#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int suffix = 0;
    for (const char& ch : s) {
        if (ch == '1' || ch == '3') {
            suffix++;
        }
    }

    int best = suffix;
    int prefix = 0;
    for (const char& ch : s) {
        if (ch == '2') {
            prefix++;
        } else if (ch == '1' || ch == '3') {
            suffix--;
        }
        best = max(best, prefix + suffix);
    }

    cout << static_cast<int>(s.size()) - best << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
