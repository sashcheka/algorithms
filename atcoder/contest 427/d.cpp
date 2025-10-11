#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }

    bool Alice_wins = true;
    bool Bob_wins = false;

    vector<bool> prev(n, false);
    vector<bool> curr(n, false);
    for (int i = 0; i < n; i++) prev[i] = (s[i] == 'A' ? Alice_wins : Bob_wins);

    for (int turn = 2 * k; turn >= 1; turn--) {
        bool is_bob_turn = turn % 2 == 0;  // we start from end -> Bob always makes a turn last
        bool is_alice_turn = turn % 2 == 1;
        if (is_bob_turn) {
            for (int u = 0; u < n; u++) {
                bool win = Alice_wins;
                for (int v : adj[u]) {
                    if (prev[v] == Bob_wins) {
                        win = Bob_wins;
                        break;
                    }
                }
                curr[u] = win;
            }
        } else if (is_alice_turn) {
            for (int u = 0; u < n; u++) {
                bool win = Bob_wins;
                for (int v : adj[u]) {
                    if (prev[v] == Alice_wins) {
                        win = Alice_wins;
                        break;
                    }
                }
                curr[u] = win;
            }
        }
        swap(prev, curr);
    }

    if (prev[0]) cout << "Alice" << '\n';  // checking prev because of swap(prev, curr)
    else cout << "Bob" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}