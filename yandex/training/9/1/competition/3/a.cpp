#include<bits/stdc++.h>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);

    string ans;
    string part;
    while (ss >> part) {
        int n = part.size();
        int i = 0;
        int j = 0;
        while (i < n && part[i] == '\'') {
            i++;
        }
        while (j < n && part[n - 1 - j] == '\'') {
            j++;
        }
        ans += part.substr(i + i, n - i - i - j - j);
    }

    cout << ans;

    return 0;
}