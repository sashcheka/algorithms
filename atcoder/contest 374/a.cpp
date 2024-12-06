#include<bits/stdc++.h>
 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    string s;
    cin >> s;

    int n = s.length();
    if (s[n - 1] == 'n' && s[n - 2] == 'a' && s[n - 3] == 's')
        cout << "Yes";
    else
        cout << "No";

    return 0;
}