#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    cin >> n;

    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        cin >> parent[i];
        parent[i]--;
    }

    int m;
    cin >> m;

    vector<unordered_set<int>> dupa(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        if (dupa[b].count(a)) {
            cout << 1 << '\n';
            continue;
        }

        bool is_parent = false;
        int temp_b = b;

        while (temp_b != -1) {
            if (temp_b == a) is_parent = true;
            dupa[b].insert(temp_b);
            temp_b = parent[temp_b];
        }

        cout << (is_parent ? 1 : 0) << '\n';
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}