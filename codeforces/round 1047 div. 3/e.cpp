#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    map<int, int> dupa;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dupa[a[i]]++;
    }

    int mex_a = 0;
    for (auto& [val, cnt] : dupa) if (val == mex_a) mex_a++;
    // cout << "mex_a: " << mex_a << '\n';

    vector<int> b = a;
    int mex_b = INT_MAX;
    unordered_map<int, int> dupa_b;
    if (k > 0) {
        k--;
        for (int i = 0; i < n; i++) {
            if (dupa[a[i]] > 1) {
                b[i] = mex_a;
                mex_b = min(mex_b, a[i]);
            } else {
                b[i] = min(b[i], mex_a);
            }
            dupa_b[b[i]]++;
        }
    } else {
        long long sum = accumulate(a.begin(), a.end(), 0);
        cout << sum << '\n';
        return;
    }
    // cout << "mex_b: " << mex_b << '\n';

    vector<int> c = b;
    int mex_c = INT_MAX;
    if (k > 0) {
        k--;
        for (int i = 0; i < n; i++) {
            if (dupa_b[b[i]] > 1) {
                c[i] = mex_b;
                mex_c = min(mex_c, b[i]);
            } else {
                c[i] = min(c[i], mex_b);
            }
        }
    } else {
        long long sum = accumulate(b.begin(), b.end(), 0);
        cout << sum << '\n';
        return;
    }
    // cout << "mex_c: " << mex_c << '\n';

    for (int i = 0; i < n; i++) {
        if (dupa_b[b[i]] > 1) {
            b[i] = mex_c;
        } else {
            b[i] = min(b[i], mex_c);
        }
    }

    if (k > 0) {
        if (k % 2 == 1) {
            long long sum = accumulate(b.begin(), b.end(), 0);
            cout << sum << '\n';
            return;
        } else {
            long long sum = accumulate(c.begin(), c.end(), 0);
            cout << sum << '\n';
            return;
        }
    } else {
        long long sum = accumulate(c.begin(), c.end(), 0);
        cout << sum << '\n';
        return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
