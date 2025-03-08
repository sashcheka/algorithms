#include <bits/stdc++.h>

using namespace std;

void solve() {
    stack<int> st;
    string s;

    getline(cin, s);    
    for (int i = 0; i < s.size(); i += 2) {
        char ch = s[i];
        
        if (string("+-*").find(ch) == string::npos) {
            st.push(ch - '0');
        } else {
            int n2 = st.top();
            st.pop();
            int n1 = st.top();
            st.pop();

            if (ch == '+') {
                st.push(n1 + n2);
            } else if (ch == '-') {
                st.push(n1 - n2);
            } else if (ch == '*') {
                st.push(n1 * n2);
            }
        }
    }

    cout << st.top();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
