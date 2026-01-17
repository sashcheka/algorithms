#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, char> dupa_red;
    unordered_map<int, char> dupa_blue;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dupa_red[a[i]] = i % 2 ? 'B' : 'R';
        dupa_blue[a[i]] = i % 2 ? 'R' : 'B';
    }

    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    for (int i = 1; i < n; i++) {
        if (dupa_red[sorted_a[i - 1]] == dupa_red[sorted_a[i]] || 
            dupa_blue[sorted_a[i - 1]] == dupa_blue[sorted_a[i]]) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
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
