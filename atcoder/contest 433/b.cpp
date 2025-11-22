#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    stack<int> st;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        if (st.empty()) cout << -1 << '\n';
        else cout << st.top() + 1 << '\n';
        st.push(i);
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}