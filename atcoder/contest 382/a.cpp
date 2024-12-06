#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;

    int cookies = 0;
    for (const char& ch : s) {
        if (ch == '@') cookies++;
    }

    cout << n - (cookies - d);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}