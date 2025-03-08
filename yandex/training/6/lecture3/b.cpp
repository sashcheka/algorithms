#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    map<int, int> dupa;
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++) {
        pair<int, int> p = make_pair(v[i], i);

        while (!st.empty() && st.top().first > p.first) {
            pair<int, int> tpp = st.top();
            st.pop();
            dupa[tpp.second] = p.second;
        }

        if (st.empty() || st.top().first <= p.first) st.push(p);
    }

    while (!st.empty()) {
        pair<int, int> p = st.top();
        st.pop();
        dupa[p.second] = -1;
    }

    for (auto& p : dupa) cout << p.second << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
