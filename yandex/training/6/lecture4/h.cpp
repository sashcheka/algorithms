#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<long long> costs;
vector<long long> not_marked;
vector<long long> marked;
vector<bool> selected;

void dfs(int u, int parent) {
    // Initialize the values for this node
    not_marked[u] = 0;
    marked[u] = costs[u];

    for (int v : tree[u]) {
        if (v == parent) continue; // Avoid processing the parent node

        // Perform DFS on child nodes
        dfs(v, u);

        // Update the costs for this node
        not_marked[u] += marked[v]; // If this node is not marked, its cost includes the marked child
        marked[u] += min(not_marked[v], marked[v]); // If this node is marked, we add the minimum of child's states
    }
}

void reconstruct(int u, int parent, bool is_parent_selected) {
    // Determine whether to mark this node
    if (is_parent_selected) {
        if (marked[u] <= not_marked[u]) {
            selected[u] = true; // Mark this node
            for (int v : tree[u]) {
                if (v != parent) reconstruct(v, u, true);
            }
        } else {
            selected[u] = false; // Do not mark this node
            for (int v : tree[u]) {
                if (v != parent) reconstruct(v, u, false);
            }
        }
    } else {
        selected[u] = true; // If parent is not selected, this node must be selected
        for (int v : tree[u]) {
            if (v != parent) reconstruct(v, u, true);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    // Initialize global structures
    tree.assign(n, vector<int>());
    costs.assign(n, 0);
    not_marked.assign(n, 0);
    marked.assign(n, 0);
    selected.assign(n, false);

    // Read the tree structure
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        --v; --u; // Convert to 0-based indexing
        tree[v].push_back(u);
        tree[u].push_back(v);
    }

    // Read the costs for marking each node
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    // Perform DFS to calculate costs
    dfs(0, -1);

    // Reconstruct the solution
    if (marked[0] <= not_marked[0]) {
        reconstruct(0, -1, true); // Mark the root if it's optimal
    } else {
        reconstruct(0, -1, false); // Do not mark the root if not optimal
    }

    // Calculate the result
    long long total_min_cost = min(marked[0], not_marked[0]);
    vector<int> marked_vertices;
    for (int i = 0; i < n; i++) {
        if (selected[i]) marked_vertices.push_back(i + 1); // Convert back to 1-based indexing
    }

    // Output the results
    cout << total_min_cost << " " << marked_vertices.size() << '\n';
    for (int i = 0; i < marked_vertices.size(); i++) {
        cout << marked_vertices[i];
        if (i + 1 < marked_vertices.size()) cout << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
