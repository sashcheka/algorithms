#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> tab(n);
    int curr = 0;
    string buffer;
    for (int i = 0; i < m; i++) {
        string input;
        cin >> input;
        if (input == "Backspace") {
            if (!tab[curr].empty()) tab[curr].pop_back();
        } else if (input == "Copy") {
            buffer = tab[curr].substr(max(0, (int)tab[curr].size() - k));
        } else if (input == "Paste") {
            if (!buffer.empty()) tab[curr] += buffer;
        } else if (input == "Next") {
            curr = (curr + 1) % n;
        } else {
            tab[curr] += input;
        }
    }

    cout << (!tab[curr].empty() ? tab[curr].substr(max(0, (int)tab[curr].size() - k)) : "Empty");

    return 0;
}