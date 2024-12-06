#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    long long count = 0;
    int l = 0;

    for (int r = 1; r < n; r++) {
        while (v[r] - v[l] > k)
            l++;

        count += l;
    }

    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
