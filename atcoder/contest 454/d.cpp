#include <bits/stdc++.h>

using namespace std;

string removeBrackets(string s) {
    if ((int)s.size() < 4) return s;
    vector<pair<char, int>> v;
    for (char ch : s) {
        if (!v.empty() && v.back().first == ch) {
            v.back().second++;
        } else {
            v.push_back({ch, 1});
        }
    }
    string res;
    int i = 0;
    while (i < (int)v.size()) {
        if (i + 2 < (int)v.size() && v[i].first == '(' && v[i + 1].first == 'x' && v[i + 1].second == 2 && v[i + 2].first == ')') {
            res += string(v[i].second - min(v[i].second, v[i + 2].second), v[i].first);
            res += string(v[i + 1].second, v[i + 1].first);
            res += string(v[i + 2].second - min(v[i].second, v[i + 2].second), v[i + 2].first);
            i += 3;
        } else {
            res += string(v[i].second, v[i].first);
            i += 1;
        }
    }
    return res;
}

bool possible(string& a, string& b) {
    if (a == b) return true;
    string rba = removeBrackets(a);
    string rbb = removeBrackets(b);
    return rba == rbb;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;
        if (possible(a, b)) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }

    return 0;
}