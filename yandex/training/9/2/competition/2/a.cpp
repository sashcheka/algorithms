#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long l = LLONG_MIN;
    long long r = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        long long x, d;
        cin >> x >> d;
        l = max(l, x - d);
        r = min(r, x + d);
        if (l > r) {
            cout << -1;
            return 0;
        }
    }

    cout << r;
    return 0;
}