#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a_prev = 1;
    n--;
    while (n--) {
        int temp = a_prev;
        int a_next = 0;
        while (temp) {
            a_next += temp % 10;
            temp /= 10;
        }
        a_prev += a_next;
    }
    cout << a_prev << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}