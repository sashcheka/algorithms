#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<pair<int, int>> st;  // type, count
    st.push({-1, 0});  // to omit st.empty() check
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        if (st.top().first != b && st.top().second >= 3) {
            ans += st.top().second;
            st.pop();
        }
        if (st.top().first == b) {
            st.top().second++;
        } else {
            st.push({b, 1});
        }
    }

    if (st.top().second >= 3) {
        ans += st.top().second;
        st.pop();
    }
    
    cout << ans;
    return 0;
}