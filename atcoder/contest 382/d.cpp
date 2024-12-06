#include<bits/stdc++.h>

using namespace std;

void go(int& n, int& m, vector<int>& curr, vector<vector<int>>& ans) {
    int size = curr.size();
    if (size == n) {
        ans.push_back(curr);
        return;
    }

    int init = size == 0 ? 1 : curr.back() + 10;
    for (int i = init; i + 10 * (n - size - 1) <= m; i++) {
        curr.push_back(i);
        go(n, m, curr, ans);
        curr.pop_back();
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> curr;
    vector<vector<int>> ans;
    go(n, m, curr, ans);

    int size = ans.size();
    cout << size << '\n';
    for (int i = 0; i < size; i++) for (int j = 0; j < n; j++) cout << ans[i][j] << " \n"[j == n - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}