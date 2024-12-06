#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int prev_known = -1;
    
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) {
            if (prev_known != -1 && a[i] <= a[prev_known]) {
                cout << "NO\n";
                return;
            }

            if (prev_known != -1) {
                int gap = i - prev_known - 1;
                if (a[i] - a[prev_known] - 1 < gap) {
                    cout << "NO\n";
                    return;
                }
                for (int j = prev_known + 1; j < i; ++j) {
                    a[j] = a[prev_known] + (j - prev_known);
                }
            }
            prev_known = i;
        }
    }
    
    if (prev_known != -1) {
        for (int i = prev_known + 1; i < n; ++i) {
            a[i] = a[prev_known] + (i - prev_known);
        }
    } else {
        for (int i = 0; i < n; ++i) {
            a[i] = i + 1;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
