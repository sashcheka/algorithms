#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string ans;
    if (n % 2) {
        if (a % 2) {
            if (b % 2) {
                ans = "Yes";
            } else {
                ans = "No";
            }
        } else {
            if (b % 2 && b > a) {
                ans = "Yes";
            } else {
                ans = "No";
            }
        }     
    } else {
        if (a % 2) {
            if (b % 2) {
                ans = "No";
            } else {
                if (b > a) {
                    ans = "Yes";
                } else {
                    ans = "No";
                }
            }
        } else {
            if (b % 2) {
                ans = "No";
            } else {
                ans = "Yes";
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
