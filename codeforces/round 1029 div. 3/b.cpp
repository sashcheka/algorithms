#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    
    int i = 0;
    for (int num = 1; num <= n; num++) {
        if (num % 2) {
            p[i] = num;
            i++;
        }
    }

    i = n - 1;
    for (int num = 1; num <= n; num++) {
        if (num % 2 == 0) {
            p[i] = num;
            i--;
        }
    }

    for (int i = 0; i < n; i++) cout << p[i] << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
