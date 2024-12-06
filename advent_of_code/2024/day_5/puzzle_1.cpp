#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

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
                    break;
                }
            }

            if (!is_cand) break;

            before.push_back(curr);
        }

        if (is_cand) {
            sum += before[before.size() / 2];
        }
    } 
        
    cout << sum;
    return 0;
}
