#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ifstream file("input_1.txt");

    string line;
    getline(file, line);

    stringstream ss(line);
    string pattern;

    vector<string> patterns;

    while (ss >> pattern) {
        if (pattern[pattern.size() - 1] == ',') pattern = pattern.substr(0, pattern.size() - 1);
        patterns.push_back(pattern);
    }   

    getline(file, line);
    long long matches = 0;
    while (getline(file, line)) {
        int n = line.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (const string& pattern : patterns) {
                int l = pattern.length();

                if (i + l <= n && line.substr(i, l) == pattern) {
                    dp[i + l] += dp[i];
                }
            }
        }

        matches += dp[n];
    }

    cout << matches;
    return 0;
}
