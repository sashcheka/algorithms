#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    int size = n + m + 1;
    vector<int> freq(size, 0);
    for (const int& x : a) freq[x]++;

    vector<int> multiplicity(size, 0);
    for (int x = 1; x < size; x++) {
        if (freq[x] == 0) continue;
        for (int y = x; y < size; y += x) {
            multiplicity[y] += freq[x];
        }
    }

    int alice = 0;
    int bob = 0;
    int both = 0;
    for (const int& y : b) {
        if (multiplicity[y] == n) alice++;
        else if (multiplicity[y] == 0) bob++;
        else both++;        
    }

    string winner;
    if (alice > bob) {
        winner = "Alice";
    } else if (alice < bob) {
        winner = "Bob";
    } else {
        winner = (both % 2) ? "Alice" : "Bob";
    }

    cout << winner << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
