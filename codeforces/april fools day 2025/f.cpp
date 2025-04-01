#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    cout << 12*a + 14*a*b + abs(a-b) + (a-3*b)*b + 2;

    return 0;
}
