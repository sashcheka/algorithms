#include<bits/stdc++.h>
 
using namespace std;
 
void solve(int l, int r) {
    if (l == r) {
        cout << 1 << '\n';
     } else {
        int count = 1;

        int curr = l;
        int offset = 1;
        while (curr + offset <= r) {
            count++;
            curr += offset;
            offset++;
        }

        cout << count << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;
        solve(l, r);
    }

    return 0;
}