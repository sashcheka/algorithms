#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long mx = INT_MIN;
    int mx_idx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > mx) {
            mx = a[i];
            mx_idx = i;
        }
    }

    if (n == 2) {
        cout << max(a[0], a[1]) << '\n';
        return;
    }

    vector<long long> b(n);
    for (int i = 0; i < n; i++) b[i] = a[(i + mx_idx) % n];

    vector<int> l(n), r(n);
    vector<int> st;

    st.reserve(n);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && b[st.back()] <= b[i]) st.pop_back();
        l[i] = st.empty() ? -1 : st.back();
        st.push_back(i);
    }

    st.clear();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && b[st.back()] < b[i]) st.pop_back();
        r[i] = st.empty() ? -1 : st.back();
        st.push_back(i);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long lv = (l[i] == -1 ? LLONG_MAX : b[l[i]]);
        long long rv = (r[i] == -1 ? LLONG_MAX : b[r[i]]);
        long long add = min(lv, rv);
        if (add < LLONG_MAX) ans += add;
    }

    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}