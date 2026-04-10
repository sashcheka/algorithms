#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <climits>

using namespace std;

unordered_map<char, char> closing = {{'}', '{'}, {']', '['}, {')', '('}};

bool is_valid(const string& s) {
    stack<char> st;

    for (const char& ch : s) {
        if (!closing.contains(ch)) {
            st.push(ch);
        } else {
            if (st.empty() || st.top() != closing[ch]) {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string s;
    cin >> s;

    if ((int)s.size() % 2) {
        cout << "NO";
        return 0;
    }

    int idx = 0;
    int mn = INT_MAX;
    int diff = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        char ch = s[i];
        if (!closing.contains(ch)) {
            diff++;
        } else {
            diff--;
        }
        if (diff < mn) {
            mn = diff;
            idx = i + 1;
        }
    }

    if (diff != 0) {
        cout << "NO";
        return 0;
    }

    s = s.substr(idx) + s.substr(0, idx);
    cout << (is_valid(s) ? "YES" : "NO");

    return 0;
}