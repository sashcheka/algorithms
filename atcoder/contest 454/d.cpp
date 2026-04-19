#include <bits/stdc++.h>

using namespace std;

string normalize(const string& s) {
    string res;
    for (const char& ch : s) {
        res += ch;
        if ((int)res.size() >= 4 && res.substr(res.size() - 4, 4) == "(xx)") {
            res.pop_back();
            res.pop_back();
            res.pop_back();
            res.pop_back();
            res += "xx";
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;
        if (normalize(a) == normalize(b)) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }

    return 0;
}