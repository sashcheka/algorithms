#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

// Function to perform topological sort using Kahn's Algorithm
bool topologicalSort(const vector<int>& nodes, const unordered_map<int, vector<int>>& adj, vector<int>& sorted) {
    unordered_map<int, int> in_degree;
    // Initialize in-degree of all nodes to 0
    for(auto node : nodes){
        in_degree[node] = 0;
    }
    // Compute in-degree based on adjacency list
    for(auto it = adj.begin(); it != adj.end(); ++it){
        for(auto v : it->second){
            in_degree[v]++;
        }
    }

    // Use a priority queue to ensure deterministic order (optional)
    priority_queue<int, vector<int>, std::greater<int>> q;
    for(auto it = in_degree.begin(); it != in_degree.end(); ++it){
        if(it->second == 0){
            q.push(it->first);
        }
    }

    while(!q.empty()){
        int u = q.top(); q.pop();
        sorted.push_back(u);
        if(adj.find(u) != adj.end()){
            for(auto v : adj.at(u)){
                in_degree[v]--;
                if(in_degree[v] == 0){
                    q.push(v);
                }
            }
        }
    }

    // Check if topological sort was possible (i.e., no cycles)
    return sorted.size() == nodes.size();
}

int main(){
    ifstream file("input_1.txt");

    // Read ordering rules
    unordered_map<int, vector<int>> ordering_rules; // X -> list of Y's
    string line;
    while(getline(file, line)){
        if(line.empty()) break; // Empty line indicates end of ordering rules
        size_t sep = line.find('|');
        if(sep != string::npos){
            int X = stoi(line.substr(0, sep));
            int Y = stoi(line.substr(sep+1));
            ordering_rules[X].push_back(Y);
        }
    }

    // Read updates
    vector<vector<int>> updates;
    while(getline(file, line)){
        if(line.empty()) continue; // Skip any empty lines
        vector<int> update;
        string num;
        stringstream ss(line);
        while(getline(ss, num, ',')){
            update.push_back(stoi(num));
        }
        updates.push_back(update);
    }

    // Process each update to identify and correct incorrectly ordered ones
    long long sum_middle = 0;
    for(auto &update : updates){
        // Build a set of pages present in the update for quick lookup
        unordered_set<int> pages(update.begin(), update.end());

        // Build adjacency list for the current update based on ordering rules
        unordered_map<int, vector<int>> adj;
        for(auto &[X, Ys] : ordering_rules){
            if(pages.find(X) != pages.end()){
                for(auto Y : Ys){
                    if(pages.find(Y) != pages.end()){
                        adj[X].push_back(Y);
                    }
                }
            }
        }

        // Perform topological sort to get the correct ordering
        vector<int> sorted;
        bool possible = topologicalSort(update, adj, sorted);

        if(!possible){
            // If topological sort is not possible (cycle detected), skip this update
            // Assuming no cycles as per problem statement
            continue;
        }

        // Check if the current update is already correctly ordered
        bool correct = true;
        if(sorted.size() != update.size()){
            correct = false;
        }
        else{
            for(int i = 0; i < sorted.size(); ++i){
                if(sorted[i] != update[i]){
                    correct = false;
                    break;
                }
            }
        }

        if(!correct){
            // If the update is incorrectly ordered, use the sorted order
            // and add the middle page number to the sum
            int n = sorted.size();
            int mid = sorted[n/2]; // For even n, this takes the lower middle
            sum_middle += mid;
        }
    }

    cout << sum_middle;
}
