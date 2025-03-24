#include <iostream>
#include <string>
#include <set>

using namespace std;

void solve() {
    int n, r, c;
    cin >> n >> r >> c;

    string s;
    cin >> s;

    pair<int, int> t = {r, c};
    pair<int, int> f = {0, 0};
    set<pair<int, int>> setik;
    setik.insert({0, 0});

    for (int i = 0; i < n; i++) {
        char dir = s[i];

        if (dir == 'N') {
            f.first++;
            t.first++;
        } else if (dir == 'W') {
            f.second++;
            t.second++;
        } else if (dir == 'S') {
            f.first--;
            t.first--;
        } else if (dir == 'E') {
            f.second--;
            t.second--;
        }

        setik.insert(f);
        if (setik.find(t) != setik.end()) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}
