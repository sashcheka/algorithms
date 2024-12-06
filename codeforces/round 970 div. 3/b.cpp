#include<bits/stdc++.h>
 
using namespace std;
 
void solve(int n, string s) {
    int root = (int)sqrt(n);

    if (root * root != n) {
        cout << "NO" << '\n';
    } else {
        string generated = "";

        for (int i = 0; i < root; i++)
            generated += '1';

        for (int i = 0; i < root - 2; i++) {
            generated += '1';
            
            for (int i = 0; i < root - 2; i++)
                generated += '0';

            generated += '1';
        }

        for (int i = 0; i < root; i++)
            generated += '1';

        if (generated == s)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        solve(n, s);
    }

    return 0;
}