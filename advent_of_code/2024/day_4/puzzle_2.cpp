#include<bits/stdc++.h>

using namespace std;

bool is_x_mas(int r, int c, const vector<vector<char>>& v) {
    if (r - 1 < 0 || r + 1 >= v.size() || c - 1 < 0 || c + 1 >= v[0].size()) return false;

    bool diag1 = false;
    bool diag2 = false;

    if ((v[r - 1][c - 1] == 'M' && v[r + 1][c + 1] == 'S') || (v[r - 1][c - 1] == 'S' && v[r + 1][c + 1] == 'M')) diag1 = true;
    if ((v[r + 1][c - 1] == 'M' && v[r - 1][c + 1] == 'S') || (v[r + 1][c - 1] == 'S' && v[r - 1][c + 1] == 'M')) diag2 = true;

    return diag1 && diag2;
}

int main() {
    ifstream file("input_2.txt");
    string line;

    vector<vector<char>> v;

    while (getline(file, line)) {
        int m = line.size();
        vector<char> l(m);
        for (int i = 0; i < m; i++) l[i] = line[i];
        v.push_back(l);
    }

    int xmas = 0;
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'A' && is_x_mas(i, j, v)) xmas++;
        }
    }

    cout << xmas;
    return 0;
}