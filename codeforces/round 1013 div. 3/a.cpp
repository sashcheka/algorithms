#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int zero = 3;
    int one = 1;
    int two = 2;
    int three = 1;
    int five = 1;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        int digit = a[i];
        if (digit == 0) zero--;
        else if (digit == 1) one--;
        else if (digit == 2) two--;
        else if (digit == 3) three--;
        else if (digit == 5) five--;

        if (zero <= 0 && one <= 0 && two <= 0 && three <= 0 && five <= 0) {
            cout << i + 1 << '\n';
            return;
        }
    }

    cout << 0 << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
