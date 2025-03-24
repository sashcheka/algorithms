#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < (n - 1) / 2; i++) s += '-';
    s += '=';
    if (n % 2 == 0) s += '=';
    for (int i = 0; i < (n - 1) / 2; i++) s += '-';
    cout << s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}