#include<bits/stdc++.h>

using namespace std;

int main() {
    set<pair<int, int>> setik;
    set<pair<int, int>> more_than_once;

    string s;
    cin >> s;
    int x = 0;
    int y = 0;
    setik.insert({x, y});
    for (const char& ch : s) {
        if (ch == 'U') {
            y--;
        } else if (ch == 'L') {
            x++;
        } else if (ch == 'D') {
            y++;
        } else if (ch == 'R') {
            x--;
        }
        if (!setik.insert({x, y}).second) {
            more_than_once.insert({x, y});
        }
    }

    cout << more_than_once.size();
    return 0;
}