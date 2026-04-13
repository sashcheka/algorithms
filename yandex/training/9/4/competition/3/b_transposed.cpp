#include <bits/stdc++.h>

using namespace std;
const int n = 10;

int main() {
    vector<string> grid(n);
    vector<string> transposed(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transposed[j] += grid[i][j];
            if (grid[i][j] == '.') continue;
            if (i < n - 1 && ((j < n - 1 && grid[i + 1][j + 1] == '#') || (j > 0 && grid[i + 1][j - 1] == '#'))) {
                cout << "NO";
                return 0;
            }
        }
    }

    auto countShips = [](const string& s, const int& c) -> int {
        int ships = 0;
        size_t pos = 0;
        while ((pos = s.find(string(c, '#'), pos)) != string::npos) {
            ships++;
            pos += c;
        }
        return ships;
    };

    vector<int> count(5);
    for (int c = 1; c < 5; c++) {
        for (int i = 0; i < n; i++) {
            count[c] += countShips(grid[i], c) + countShips(transposed[i], c);
        }
    }

    if (count[4] == 1 && count[3] == 3 && count[2] == 7 && count[1] == 40) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}