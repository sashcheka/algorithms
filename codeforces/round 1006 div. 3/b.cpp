#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    long long mouth = 0;
    long long eye = 0;
    for (const char& ch : s) {
        if (ch == '_') mouth++;
        else if (ch == '-') eye++;
    }

    long long price;
    if (eye % 2 == 1) {
        price = (eye / 2) * (eye / 2 + 1) * mouth;
    } else if (eye % 2 == 0) {
        price = (eye / 2) * (eye / 2) * mouth;
    }
    
    cout << price << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
