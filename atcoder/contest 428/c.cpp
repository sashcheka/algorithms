#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    
    stack<pair<int, int>> st;
    st.push({0, 0});

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            char bracket;
            cin >> bracket;
            auto [state, min_prev_state] = st.top();
            if (bracket == '(') state++;
            else if (bracket == ')') state--;
            min_prev_state = min(min_prev_state, state);
            st.push({state, min_prev_state});
        } else if (type == 2) {
            st.pop();
        }

        auto [state, min_prev_state] = st.top();
        if (state == 0 && min_prev_state >= 0) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}