#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a % b == 0) {
        cout << a / b;
        return;
    }

   int floor = a / b;
   int ceiling = (a + b - 1) / b;

   if (abs((float)floor - ((float)a / b)) < abs((float)ceiling - ((float)a / b))) cout << floor;
   else cout << ceiling;
 }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}