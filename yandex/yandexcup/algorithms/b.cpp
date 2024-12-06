#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll m = 0;
    for (int i = 1; i < n - 1; i++) {
        if (v[i - 1] < v[i] && v[i] > v[i + 1]) {
            int left = i - 1;

            while (left > 0 && v[left] > v[left - 1])
                left--;

            int right = i + 1;
            while (right < n - 1 && v[right] > v[right + 1])
                right++;

            m += (ll)(i - left) * (right - i);
        }
    }

    cout << m << '\n';    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
