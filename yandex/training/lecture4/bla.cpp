#include <bits/stdc++.h>

using namespace std;

void dfs(int node, const vector<vector<int>>& tree, vector<int>& coins, vector<int>& leaves) {
    if (tree[node].empty()) {
        leaves[node] = 1;
        coins[node] = 1;
        return;
    }

    leaves[node] = 0;
    coins[node] = 0;
    for (int subordinate : tree[node]) {
        dfs(subordinate, tree, coins, leaves);
        leaves[node] += leaves[subordinate];
        coins[node] += coins[subordinate] + leaves[subordinate];
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for (int i = 2; i <= n; i++) {
        int manager;
        cin >> manager;
        tree[manager].push_back(i);
    }

    vector<int> coins(n + 1, 0);
    vector<int> leaves(n + 1, 0);

    dfs(1, tree, coins, leaves);
    coins[1] += 1; // Добавляем 1 монету генеральному директору за последнее задание

    for (int i = 1; i <= n; i++)
        cout << coins[i] << " ";

    return 0;
}
