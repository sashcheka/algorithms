#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<bool> skip(n, false);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        skip[(i - a[i] + n) % n] = true;
    }

    for (int i = 0; i < n; i++) {
        if (!skip[i]) {
            cout << i;
            return 0;
        }
    }

    cout << -1;
    return 0;
}
