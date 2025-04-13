#include<iostream>
#include<string>

using namespace std;

void solve() {
    string p, s;
    cin >> p >> s;

    int n = p.size();
    int m = s.size();

    int i = 0;
    int j = 0;

    while (i < n && j < m) {
        if (p[i] != s[j]) {
            cout << "NO" << '\n';
            return;
        }

        int count_p = 0;
        char ch = p[i];
        while (i < n && ch == p[i]) {
            count_p++;
            i++;
        }

        int count_s = 0;
        while (j < m && ch == s[j]) {
            count_s++;
            j++;
        }

        if (count_s < count_p || count_s > 2 * count_p) {
            cout << "NO" << '\n';
            return;
        }
    }

    if (i == n && j == m) cout << "YES" << '\n';
    else cout << "NO" << '\n';

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
