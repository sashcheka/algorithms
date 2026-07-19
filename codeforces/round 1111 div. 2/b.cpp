#include "../headers.h"

using namespace std;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;

    if (m < k) {
        cout << "NO" << "\n"; 
        return;
    }

    cout << "YES" << "\n";
    for (int i = 0; i < n; i++) {
        int a;
        if (i % k) {
            a = 1;
        } else {
            a = m - (k - 1);
        }
        cout << a << " \n"[i == n - 1];
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
