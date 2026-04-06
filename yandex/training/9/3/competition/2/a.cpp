#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int x = 0;
    int y = 0;
    map<pair<int, int>, int> mapka;
    mapka[{x, y}]++;
    int ans = 0;
    for (const char& ch : s) {
        if (ch == 'U') y--;
        else if (ch == 'L') x++;
        else if (ch == 'D') y++;
        else if (ch == 'R') x--;

        if (mapka[{x, y}]++ == 1) ans++;
    }

    cout << ans;
    return 0;
}