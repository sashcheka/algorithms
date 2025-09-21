#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    cin >> n;
    
    string s; 
    cin >> s;

    vector<int> p(n, -1);

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') p[i] = i;
    }

    int i = 0;
    while (i < n) {
        if (s[i] == '1') {
            i++;
            continue;
        }

        int l = i;
        while (i < n && s[i] == '0') i++;

        int r = i - 1;
        int len = r - l + 1;
        if (len == 1) {
            cout << "NO" << '\n';
            return;
        }

        for (int j = l; j < r; j++) p[j] = j + 1;
        p[r] = l;
    }

    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) cout << p[i] + 1 << " \n"[i == n - 1];

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
