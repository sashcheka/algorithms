#include<bits/stdc++.h>

using namespace std;

const int x = 0;
const int y = 1;
const int m = 4;

bool is_valid(
    const array<int, 2>& a, 
    const array<int, 2>& b, 
    const array<int, 2>& c, 
    const array<int, 2>& d) 
{
    if (abs(a[x] - b[x]) != abs(c[x] - d[x]) || abs(a[y] - b[y]) != abs(c[y] - d[y])) {
        return false;
    }

    if (pow(a[x] - b[x], 2) + pow(a[y] - b[y], 2) != pow(c[x] - d[x], 2) + pow(c[y] - d[y], 2)) {
        return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        vector<array<int, 2>> p(m);
        for (int i = 0; i < m; i++) {
            cin >> p[i][x] >> p[i][y];
        }

        if (is_valid(p[0], p[1], p[2], p[3]) ||
            is_valid(p[0], p[2], p[1], p[3]) ||
            is_valid(p[0], p[3], p[1], p[2])) 
        {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}