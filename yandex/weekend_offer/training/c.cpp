#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int prev;
    int curr;
    if (n) {
        cin >> prev;
        cout << prev << '\n';
        n--;
    }

    while (n--) {
        cin >> curr;
        if (prev != curr) cout << curr << '\n';
        prev = curr;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}
