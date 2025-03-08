#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string w, s;
    cin >> n >> w >> s;

    stack<char> st;
    for (const char& ch : s) {
        if (ch == '(' || ch == '[') {
            st.push(ch);
        } else {
            st.pop(); 
        }
    }

    unordered_map<char, char> match = { {')', '('}, {']', '['} };

    int st_size = st.size();
    int remain = n - s.length();
    string res = s;

    for (int i = s.length(); i < n; i++) {
        for (const char& ch : w) {
            if (ch == '(' || ch == '[') {
                if (st_size + 1 <= remain) {
                    res += ch;
                    st.push(ch);
                    st_size++;
                    remain--;
                    break;
                }
            } else {
                if (st_size > 0 && st.top() == match[ch]) {
                    res += ch;
                    st.pop();
                    st_size--;
                    remain--;
                    break;
                }
            }
        }
    }

    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}