#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    set<pair<int, int>> setik;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a < 0 || b < 0 || a + b + 1 != n) continue;
        if (setik.insert({a, b}).second) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}