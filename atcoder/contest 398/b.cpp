#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n = 7;

    vector<int> a(n);
    unordered_map<int, int> dupa;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dupa[a[i]]++;
    }

    bool two = false;
    bool three = false;

    for (auto& [value, count] : dupa) {
        if (!three && count >= 3) {
            three = true;
        } else if (!two && count >= 2) {
            two = true;
        }
    }

    if (two && three) cout << "Yes";
    else cout << "No";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}