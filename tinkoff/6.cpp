#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> exec_time(n);        // Time taken for each process
    vector<vector<int>> adj(n);            // Adjacency list for dependencies
    vector<int> indegree(n, 0);            // To store in-degree of each node

    // Reading input data
    for (int i = 0; i < n; ++i) {
        cin >> exec_time[i];               // Execution time for process i
        int k;
        while (cin >> k && k != 0) {
            adj[k-1].push_back(i);         // Process i depends on process k-1
            indegree[i]++;                 // Increase in-degree for process i
        }
    }

    queue<int> q;                          // Queue for Kahn's Algorithm (topological sort)
    vector<long long> dp(n, 0);            // To store minimum completion time for each process

    // Start with all nodes that have no dependencies (in-degree 0)
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
            dp[i] = exec_time[i];          // If no dependencies, process can start immediately
        }
    }

    // Topological Sort using Kahn's Algorithm
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // For each process v that depends on process u
        for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u] + exec_time[v]); // Update dp[v] with the max time it can start
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);                 // If all dependencies of v are processed, add v to the queue
            }
        }
    }

    // The result is the maximum time required to finish all processes
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
