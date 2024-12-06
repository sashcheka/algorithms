#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '@' && d > 0) {
            s[i] = '.';
            d--;
        }
    }

    cout << s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}