#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> p(n), s(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> s[i];

    if(p[n-1] != s[0]) {
        cout << "NO" << '\n';
        return;
    }

    for(int i = 1; i < n; i++){
        if(p[i-1] % p[i] != 0) {
            cout << "NO" << '\n';
            return;
        }
    }
    for(int i = 0; i+1 < n; i++){
        if(s[i+1] % s[i] != 0) {
            cout << "NO" << '\n';
            return; 
        }
    }

    for(int i = 1; i < n; i++){
        long long g = std::gcd(p[i-1], s[i]);
        if(p[i] % g != 0) {
            cout << "NO" << '\n';
            return;
        }
    }

    for(int i = 0; i+1 < n; i++){
        long long g = std::gcd(p[i], s[i+1]);
        if(s[i] % g != 0) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
