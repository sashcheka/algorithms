#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    getline(cin, s);

    stack<char> st;
    string postfix;
    int open = 0;
    int close = 0;

    for (size_t i = 0; i < s.size(); ++i) {
        char ch = s[i];

        if (ch == ' ') continue;

        if (isdigit(ch)) {
            while (i < s.size() && isdigit(s[i])) {
                postfix += s[i];
                i++;
            }
            postfix += ' ';
            i--;
        } else {
            if (ch == '+' || ch == '-' || ch == '*') {
                while (!st.empty() && st.top() != '(' &&
                       ((ch == '+' || ch == '-') || (ch == '*' && st.top() == '*'))) {
                    postfix += st.top();
                    postfix += ' ';
                    st.pop();
                }
                st.push(ch);
            } else if (ch == '(') {
                open++;
                st.push(ch);
            } else if (ch == ')') {
                close++;
                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    postfix += ' ';
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') st.pop();
            } else {
                cout << "WRONG";
                return;
            }
        }
    }

    while (!st.empty()) {
        if (st.top() == '(' || st.top() == ')') {
            cout << "WRONG";
            return;
        }
        postfix += st.top();
        postfix += ' ';
        st.pop();
    }

    if (open != close) {
        cout << "WRONG";
        return;
    }

    stack<int> postfix_st;
    istringstream tokens(postfix);
    string token;

    while (tokens >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            postfix_st.push(stoi(token));
        } else if (token == "+" || token == "-" || token == "*") {
            if (postfix_st.size() < 2) {
                cout << "WRONG";
                return;
            }
            int n2 = postfix_st.top(); postfix_st.pop();
            int n1 = postfix_st.top(); postfix_st.pop();

            if (token == "+") {
                postfix_st.push(n1 + n2);
            } else if (token == "-") {
                postfix_st.push(n1 - n2);
            } else if (token == "*") {
                postfix_st.push(n1 * n2);
            }
        } else {
            cout << "WRONG";
            return;
        }
    }

    if (postfix_st.size() != 1) {
        cout << "WRONG";
    } else {
        cout << postfix_st.top();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
