#include<bits/stdc++.h>

using namespace std;

int horizontal(int r, int c, const vector<vector<char>>& v) {
    if (c + 3 >= v[0].size()) return 0;

    int xmas = 0;
    if (v[r][c] == 'X' && v[r][c + 1] == 'M' && v[r][c + 2] == 'A' && v[r][c + 3] == 'S') xmas++;
    if (v[r][c] == 'S' && v[r][c + 1] == 'A' && v[r][c + 2] == 'M' && v[r][c + 3] == 'X') xmas++;

    return xmas;
}

int vertical(int r, int c, const vector<vector<char>>& v) {
    if (r + 3 >= v.size()) return 0;

    int xmas = 0;
    if (v[r][c] == 'X' && v[r + 1][c] == 'M' && v[r + 2][c] == 'A' && v[r + 3][c] == 'S') xmas++;
    if (v[r][c] == 'S' && v[r + 1][c] == 'A' && v[r + 2][c] == 'M' && v[r + 3][c] == 'X') xmas++;

    return xmas;
}

int diagonal(int r, int c, const vector<vector<char>>& v) {
    int xmas = 0;

    if (r - 3 >= 0 && c - 3 >= 0) {
        if (v[r][c] == 'X' && v[r - 1][c - 1] == 'M' && v[r - 2][c - 2] == 'A' && v[r - 3][c - 3] == 'S') xmas++;
        if (v[r][c] == 'S' && v[r - 1][c - 1] == 'A' && v[r - 2][c - 2] == 'M' && v[r - 3][c - 3] == 'X') xmas++;
    }

    if (r - 3 >= 0 && c + 3 < v[0].size()) {
        if (v[r][c] == 'X' && v[r - 1][c + 1] == 'M' && v[r - 2][c + 2] == 'A' && v[r - 3][c + 3] == 'S') xmas++;
        if (v[r][c] == 'S' && v[r - 1][c + 1] == 'A' && v[r - 2][c + 2] == 'M' && v[r - 3][c + 3] == 'X') xmas++;
    }

    return xmas;    
}

int main() {
    ifstream file("input_1.txt");
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
            xmas += horizontal(i, j, v);
            xmas += vertical(i, j, v);
            xmas += diagonal(i, j, v);
        }
    }

    cout << xmas;
    return 0;
}
