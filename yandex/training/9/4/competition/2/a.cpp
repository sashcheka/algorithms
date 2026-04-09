#include<bits/stdc++.h>

using namespace std;

bool check(const int& start, const string& ss, const int& n) {
    stack<char> st;
    for (int i = start; i < start + n; i++) {
        char ch = ss[i];
        if (ch == '(') {
            st.push(')');
        } else if (ch == '{') {
            st.push('}');
        } else if (ch == '[') {
            st.push(']');
        } else if (st.empty() || st.top() != ch) {
            return false;
        } else {
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s;
    cin >> s;
    int n = (int)s.size();

    if (n == 0) {
        cout << "YES";
        return 0;
    }

    string ss = s + s;
    for (int i = 0; i < n; i++) {
        if (check(i, ss, n)) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}