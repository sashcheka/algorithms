#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    long long c;
    cin >> c;

    string s;
    cin >> s;

    vector<long long> cumul_rud(n + 1, 0);
    vector<long long> a(n + 1, 0);
    vector<long long> b(n + 1, 0);

    for (int i = 0; i < n; i++) {
        a[i + 1] = a[i] + (s[i] == 'a' ? 1 : 0);
        b[i + 1] = b[i] + (s[i] == 'b' ? 1 : 0);
        cumul_rud[i + 1] = cumul_rud[i];

        if (s[i] == 'b')
            cumul_rud[i + 1] += a[i];
    }

    int length = 0;
    int l = 0;

    for (int r = 0; r < n; r++) {
        while (l <= r) {
            long long rud = cumul_rud[r + 1] - cumul_rud[l] - a[l] * (b[r + 1] - b[l]);

            if (rud <= c)
                break;

            l++;
        }
        
        length = max(length, r - l + 1);
    }

    cout << length << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
