#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    long long c;
    cin >> c;

    string s;
    cin >> s;

    vector<long long> a(n + 1, 0);
    for (int i = 1; i < n + 1; i++) {
        if (s[i - 1] == 'a')
            a[i] = a[i - 1] + 1;
        else
            a[i] = a[i - 1];
    }

    long long pairs = 0;
    for (int i = 1; i < n + 1; i++)
        if (s[i - 1] == 'b')
            pairs += a[i];

    long long goal;
    if (pairs <= c) {
        cout << n;
        return;
    } else {
        goal = pairs - c;
    }

    int to_delete = 0;
    for (int i = 1; i < n + 1; i++) {
        if (a[i] != 0 && goal >= a[i]) {
            goal -= a[i];
            to_delete++;
        }
    }

    cout << n - to_delete;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
