#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> dupa;
    dupa.reserve(3e5);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dupa[a[i]]++;
    }

    int result = INT_MIN;
    int result_label = -1;
    for (int i = 0; i < n; i++) {
        if (dupa[a[i]] == 1) {
            if (a[i] > result) {
                result = a[i];
                result_label = i + 1;
            }
        }
    }

    cout << result_label;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}