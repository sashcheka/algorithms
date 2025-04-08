#include <iostream>

using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    int x, k;
    cin >> x >> k;

    if (k == 1) {
        cout << (is_prime(x) ? "YES" : "NO") << '\n';
    } else {
        if (x == 1) {
            cout << (k == 2 ? "YES" : "NO") << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
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
