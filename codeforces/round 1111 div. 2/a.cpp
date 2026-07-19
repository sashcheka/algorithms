#include "../headers.h"

using namespace std;

void solve() {
    int n;
    cin >> n;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
    }

    if (sum % 4 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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
