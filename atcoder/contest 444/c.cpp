#include <bits/stdc++.h>
using namespace std;

bool is_valid(long long target, const vector<long long>& a, const int& n) {
    int l = 0;
    int r = n - 1;
    while (r >= 0 && a[r] == target) r--;
    while (l < r) {
        if (a[l] + a[r] != target) return false;
        l++;
        r--;
    }
    if (l == r) return false;
    return true;
};

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long mn = LLONG_MAX;
    long long mx = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    sort(a.begin(), a.end());

    long long l1 = mx;
    long long l2 = mx + mn;
    vector<long long> ans;
    if (is_valid(l1, a, n)) ans.push_back(l1);
    if (n % 2 == 0 && l2 != l1 && is_valid(l2, a, n)) ans.push_back(l2);

    sort(ans.begin(), ans.end());
    int m = ans.size();
    for (int i = 0; i < m; i++) cout << ans[i] << " \n"[i == m - 1];
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}