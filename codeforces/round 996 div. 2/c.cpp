#include<bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<long long> row_sum(n);
    vector<long long> col_sum(m);
    vector<vector<long long>> grid(n, vector<long long>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
        row_sum[i] += grid[i][j];
        col_sum[j] += grid[i][j];
    }

    int i = 0;
    int j = 0;
    for (const char& ch : s) {
        if (ch == 'R') {
            j++;
            if (col_sum[j - 1] > 0) grid[i][j - 1] = -col_sum[j - 1];
            else if (col_sum[j - 1] == 0) grid[i][j - 1] = 0;
            else if (col_sum[j - 1] < 0) grid[i][j - 1] = -col_sum[j - 1];
            row_sum[i] += grid[i][j - 1];
        } else if (ch == 'D') {
            i++;
            if (row_sum[i - 1] > 0) grid[i - 1][j] = -row_sum[i - 1];
            else if (row_sum[i - 1] == 0) grid[i - 1][j] = 0;
            else if (row_sum[i - 1] < 0) grid[i - 1][j] = -row_sum[i - 1];
            col_sum[j] += grid[i - 1][j];
        }
    }

    char ch = s.back();
    if (ch == 'R') {
        j++;
        if (col_sum[j - 1] > 0) grid[i][j - 1] = -col_sum[j - 1];
        else if (col_sum[j - 1] == 0) grid[i][j - 1] = 0;
        else if (col_sum[j - 1] < 0) grid[i][j - 1] = -col_sum[j - 1];
        row_sum[i] += grid[i][j - 1];
    } else if (ch == 'D') {
        i++;
        if (row_sum[i - 1] > 0) grid[i - 1][j] = -row_sum[i - 1];
        else if (row_sum[i - 1] == 0) grid[i - 1][j] = 0;
        else if (row_sum[i - 1] < 0) grid[i - 1][j] = -row_sum[i - 1];
        col_sum[j] += grid[i - 1][j];
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cout << grid[i][j] << " \n"[j == m - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}