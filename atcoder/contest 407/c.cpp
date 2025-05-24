#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    long long presses = 0;
    long long b_presses = 0;

    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        int digit = s[i] - '0';
        int curr_b_presses = ((digit - b_presses) % 10 + 10) % 10;
        presses += curr_b_presses + 1;
        b_presses += curr_b_presses;
    }

    cout << presses;
 }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}