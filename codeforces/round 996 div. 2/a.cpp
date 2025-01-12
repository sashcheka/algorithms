#include<bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    int diff = abs(a - b);
    if (diff % 2 == 1) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();

    return 0;
}