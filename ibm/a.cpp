#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    stack<char> st;
    string str;
    cin >> str;

    for (const char& ch : str) {
        if (!st.empty() && ch == 'B')
            st.pop();
        else
            st.push(ch);
    }

    cout << st.size();

    return 0;
}
