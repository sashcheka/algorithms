#include<bits/stdc++.h>

using namespace std;

void solve() {
    int r, c;
    cin >> r >> c;

    vector<vector<char>> matrix(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }

    set<string> setik;
    for (int i = 0; i < r; i++) {
        string s = "";
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] == '#') {
                if (s.size() >= 2) setik.insert(s);
                s = "";
            } else {
                s += matrix[i][j];
            }
        }
        if (s.size() >= 2) setik.insert(s);
    }   

    for (int i = 0; i < c; i++) {
        string s;
        for (int j = 0; j < r; j++) {
            if (matrix[j][i] == '#') {
                if (s.size() >= 2) setik.insert(s);
                s = "";
            } else {
                s += matrix[j][i];
            }
        }

        if (s.size() >= 2) setik.insert(s);
    }

    cout << *setik.begin();
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}