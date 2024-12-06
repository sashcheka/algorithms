#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int curr_l = 0;
    int max_l = 0;

    bool b;
    while (n--) {
        cin >> b;

        if (b == 1) {
            curr_l++;
            max_l = max(max_l, curr_l);
        } else {
            curr_l = 0;
        }
    }

    cout << max_l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}
