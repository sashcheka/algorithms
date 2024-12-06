#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> order(const vector<int>& before, const unordered_map<int, unordered_set<int>>& after) {
    unordered_map<int, int> in_degree;  // Tracks the in-degree of each node (page)
    for (const auto& entry : after) {
        for (int after_page : entry.second) {
            in_degree[after_page]++;
        }
    }

    queue<int> q;
    vector<int> sorted_order;

    // Add nodes with zero in-degree (no dependencies) to the queue
    for (int page : before) {
        if (in_degree.find(page) == in_degree.end()) {
            q.push(page);  // No dependencies, so it can go first
        }
    }

    // Perform topological sorting
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        sorted_order.push_back(curr);

        // Reduce the in-degree of the dependent nodes
        if (after.find(curr) != after.end()) {
            for (int next : after.at(curr)) {
                in_degree[next]--;
                if (in_degree[next] == 0) {
                    q.push(next);
                }
            }
        }
    }

    return sorted_order;  // This is the correct order
}

int main() {
    ifstream file("test_1.txt");

    string line;
    unordered_map<int, unordered_set<int>> after;
    while (getline(file, line)) {
        if (line.find('|') == string::npos) break;

        stringstream ss(line);
        int before, aft;
        char delimiter;

        ss >> before >> delimiter >> aft;
        after[before].insert(aft);
    }

    int sum = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<int> before;
        string token;

        bool is_cand = true;

        while (getline(ss, token, ',')) {
            int curr = stoi(token);

            for (int i : before) {
                if (after[curr].find(i) != after[curr].end()) {
                    is_cand = false;
                }
            }

            before.push_back(curr);
        }

        if (!is_cand) {
            vector<int> temp = order(before, after);
            sum += temp[temp.size() / 2];
        }
    } 
        
    cout << sum;
    return 0;
}
