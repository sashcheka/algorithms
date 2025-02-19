#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    map<long long, int, greater<long long>> dupa; // total_sum, index of array
    vector<vector<int>> arrays(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        long long interim_sum = 0;
        long long total = 0;
        
        for (int j = 0; j < m; j++) {
            cin >> arrays[i][j];
            interim_sum += arrays[i][j];
            total += interim_sum;
        }
        dupa[total] = i;
    }

    long long interim_sum = 0;
    long long total = 0;

    for (auto& [product, idx] : dupa) {
        for (int i = 0; i < m; i++) {
            interim_sum += arrays[idx][i];
            total += interim_sum;
        }
    }

    cout << total << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
