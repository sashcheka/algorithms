#include "../headers.h"

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    if (a == b) {
        cout << 0 << "\n";
        return;
    }

    vector<int> zeroes(n, 0);
    vector<int> ones(n, 1);
    if (a == zeroes || b == ones) {
        cout << -1 << "\n";
        return;
    }

    int d = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1 && b[i] == 0) {
            d++;
        }
    }

    if (d % 2) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
