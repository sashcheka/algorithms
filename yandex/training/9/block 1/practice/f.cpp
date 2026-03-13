#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll min1 = LLONG_MAX;
    ll min2 = LLONG_MAX;
    ll max1 = LLONG_MIN;
    ll max2 = LLONG_MIN;

    ll num;
    while (cin >> num) {
        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }

        if (num > max1) {
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max2 = num;
        }
    }

    ll cand1 = min1 * min2;
    ll cand2 = max1 * max2;
    if (cand1 <= cand2) {
        cout << max2 << " " << max1 << "\n";        
    } else {
        cout << min1 << " " << min2 << "\n";        
    }

    return 0;
}