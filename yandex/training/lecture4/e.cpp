#include<bits/stdc++.h>

using namespace std;

void dfs(int root, int parent, vector<vector<int>>& dupa, vector<int>& members_count) {
    members_count[root] = 1;

    for (const int& child : dupa[root]) {
        if (child == parent) continue;
        dfs(child, root, dupa, members_count);
        members_count[root] += members_count[child];
    }
}

void iter(int& n, vector<vector<int>>& dupa, vector<int>& members_count) {
    stack<pair<int, int>> stack;
    vector<bool> visited(n + 1, false);
    stack.push({1, -1});

    while (!stack.empty()) {
        pair<int, int> p = stack.top();
        int node = p.first;
        int parent = p.second;

        if (!visited[node]) {
            visited[node] = true;
            for (const int& child : dupa[node]) {
                if (child == parent) continue;
                stack.push({child, node});
            }
        } else {
            members_count[node]++;
            for (const int& child : dupa[node]) {
                if (child == parent) continue;
                members_count[node] += members_count[child];
            }
            stack.pop();
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> dupa(n + 1);

    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        dupa[a].push_back(b);
        dupa[b].push_back(a);
    }

    vector<int> members_count(n + 1, 0);
    // dfs(1, -1, dupa, members_count);
    iter(n, dupa, members_count);

    for (int i = 1; i <= n; i++) cout << members_count[i] << ' ';
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}