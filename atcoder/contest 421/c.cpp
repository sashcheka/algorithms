#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    if (n == 2) {
        cout << 0;
        return;
    }

    vector<int> pos;
    for (int i = 0; i < n*2; i++) if (s[i] == 'A') pos.push_back(i);

    long long even = 0;
    long long odd = 0;
    for (int i = 0; i < pos.size(); i++) {
        odd += abs(pos[i] - (2*i+1));
        even += abs(pos[i] - 2*i);
    }

    cout << min(even, odd);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}