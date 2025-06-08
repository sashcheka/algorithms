#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<long long> a(n);
    for (auto& v : a) cin >> v;

    long long d = a[1] - a[0];
    bool ok = true;
    for (int i = 2; i < n && ok; i++) if (a[i] - a[i - 1] != d) ok = false;

    if (!ok) { 
        cout << "NO\n"; 
        return; 
    }

    long long num = a[0] + (long long)d * n;
    long long den = 1 + n;

    if (num % den) { 
        cout << "NO\n"; 
        return; 
    }

    // d = x - y
    long long x = num / den;
    long long y = x - d;
    cout << (y >= 0 ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
