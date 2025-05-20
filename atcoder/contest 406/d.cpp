#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<int> x(n), y(n);
    vector<vector<int>> in_row(h), in_col(w);
    vector<int> count_row(h, 0), count_col(w, 0);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        --x[i]; 
        --y[i];
        in_row[x[i]].push_back(i);
        in_col[y[i]].push_back(i);
        count_row[x[i]]++;
        count_col[y[i]]++;
    }

    vector<char> removed(n, false);

    int q;
    cin >> q;
    while (q--) {
        int op, v;
        cin >> op >> v;
        --v;

        if (op == 1) {
            cout << count_row[v] << "\n";
            count_row[v] = 0;

            for (int idx : in_row[v]) {
                if (!removed[idx]) {
                    removed[idx] = true;
                    count_col[y[idx]]--;
                }
            }
            in_row[v].clear();
        } else if (op == 2) {
            cout << count_col[v] << "\n";
            count_col[v] = 0;

            for (int idx : in_col[v]) {
                if (!removed[idx]) {
                    removed[idx] = true;
                    count_row[x[idx]]--;
                }
            }
            in_col[v].clear();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
