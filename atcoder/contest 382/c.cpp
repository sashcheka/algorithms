#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), sushi(m, -1);
    vector<pair<int, int>> b(m);
    for (int i = 0; i < n; i++) cin >> a[i];

    int s;
    for (int i = 0; i < m; i++) {
        cin >> s;
        b[i] = {s, i};
    }

    sort(b.begin(), b.end(), greater<>());

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (b[j].first >= a[i]) {
            sushi[b[j].second] = i + 1;
            j++;
        }
    }

    for (int i = 0; i < m; i++) cout << sushi[i] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}