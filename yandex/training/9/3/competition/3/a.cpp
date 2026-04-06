#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = (int)s.size();
    int total = 0;
    int worst = 0;
    for (char ch : s) {
        worst = max(worst, ch - 'A');
        total += ch - 'A';
    }

    int rounded_avg = (total + (n - 1) / 2) / n;
    int ans = max(rounded_avg, worst - 1);
    cout << char(ans + 'A');

    return 0;
}