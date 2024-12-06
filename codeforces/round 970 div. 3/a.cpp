#include<bits/stdc++.h>
 
using namespace std;
 
void solve(int a, int b) {
    if (a == 0) {
        if (b % 2)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    } else {
        if (a % 2 == 1)
            cout << "NO" << '\n';
        else {
            if (b % 2)
                cout << "YES" << '\n';
            else
                cout << "YES" << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        solve(a, b);
    }

    return 0;
}