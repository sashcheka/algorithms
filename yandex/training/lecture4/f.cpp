#include<bits/stdc++.h>

using namespace std;
#define ll long long

pair<ll, ll> dfs(int node, const vector<vector<int>>& tree, vector<ll>& coins) {
    if (tree[node].empty()) {
        coins[node] = 1;
        return {1, 1};
    }

    pair<ll, ll> p;
    ll total_coins = 0;
    ll depth = 0;
    for (int subordinate : tree[node]) {
        p = dfs(subordinate, tree, coins);
        total_coins += p.first + p.second;
        depth += p.second;
    }

    coins[node] = total_coins + 1;

    return {coins[node], depth + 1};
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for (int i = 2; i <= n; i++) {
        int manager;
        cin >> manager;
        tree[manager].push_back(i);
    }

    vector<ll> coins(n + 1, 0);

    dfs(1, tree, coins);

    for (int i = 1; i <= n; i++) cout << coins[i] << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}