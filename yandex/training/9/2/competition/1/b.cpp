#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];

    auto valid = [&](const int& m) -> bool {
        unordered_map<string, int> dupa;
        dupa.reserve(n);
        for (const string& word : words) {
            ++dupa[word.substr(0, m + 1)];
        }
        for (const auto& [prefix, count] : dupa) {
            if (count % 2) {
                return false;
            }
        }
        return true;
    };

    int l = 0;
    int r = words[0].size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (valid(m)) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << l;

    return 0;
}