#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    long long total_employees = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_employees += a[i];
    }

    long long half = (total_employees + 1) / 2;
    long long cumulative = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        cumulative += a[i];
        if (cumulative >= half) {
            k = i;
            break;
        }
    }

    long long total_steps = 0;
    for (int i = 0; i < n; i++) total_steps += 1LL * a[i] * abs(i - k);
    cout << total_steps;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
