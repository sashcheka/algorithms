#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, b;
    cin >> n >> b;

    vector<int> a(n);
    int idx;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == b) idx = i;
        if (a[i] > b)
            a[i] = 1;
        else if (a[i] < b)
            a[i] = -1;
        else
            a[i] = 0;
    }

    unordered_map<int, int> counts;
    int balance = 0;
    counts[0] = 1;

    for (int i = idx + 1; i < n; i++) {
        balance += a[i];
        counts[balance]++;
    }

    balance = 0;
    long long result = 0;
    for (int i = idx; i >= 0; --i) {
        balance += a[i];

        if (counts.find(-balance) != counts.end()) result += counts[-balance];
    }

    cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
