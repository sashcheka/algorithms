#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        freq[a]++;
    }

    int MIN = 0;
    while (MIN <= n && freq[MIN] != 0) MIN++;

    vector<int> diff(n + 2, 0);
    for (int i = 0; i <= MIN; i++) {
        int l = freq[i];
        int r = n - i;
        if (l <= r) {
            diff[l]++;
            diff[r + 1]--;
        }
    }

    vector<int> prefix(n + 1);
    int run = 0;
    for (int i = 0; i <= n; i++) {
        run += diff[i];
        prefix[i] = run;
    }
    for (int i = 0; i <= n; i++) cout << prefix[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
