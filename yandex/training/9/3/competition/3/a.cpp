#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = (int)s.size();
    int total = 0;
    int worst = INT_MIN;
    for (char ch : s) {
        worst = max(worst, ch - 'A');
        total += ch - 'A';
    }

    float avg = static_cast<float>(total) / n;
    int lo = avg;
    int hi = avg + 1;
    float to_lo = avg - lo;
    float to_hi = hi - avg;

    int ans = lo;
    if (to_lo > to_hi) {
        ans = hi;
    }

    if (ans < worst - 1) {
        ans = worst - 1;
    }

    cout << char(ans + 'A');

    return 0;
}