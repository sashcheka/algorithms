#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, tr, tc;
    cin >> n >> tr >> tc;

    string s;
    cin >> s;

    vector<bool> smoke(n);
    unordered_map<int, pair<int, int>> dupa;
    int id = 0;
    dupa[0] = {id, 0};
    id++;

    for (int t = 1; t <= n; t++) {
        char dir = s[t - 1];

        int nr = 0, nc = 0;
        bool new_smoke = true;
        if (dir == 'N') {
            nr--;
        } else if (dir == 'W') {
            nc--;
        } else if (dir == 'S') {
            nr++;
        } else if (dir == 'E') {
            nc++;
        }

        bool exists = false;
        for (auto& [_, pos] : dupa) {
            auto& [cr, cc] = pos;

            if (dir == 'N') {
                cr--; 
            } else if (dir == 'W') {
                cc--; 
            } else if (dir == 'S') {
                cr++; 
            } else if (dir == 'E') {
                cc++; 
            }
            
            exists |= cr == tr && cc == tc;
            if (cr == nr && cc == nc) new_smoke = false;
        }

        if (new_smoke) {
            dupa[id] = {nr, nc};
            id++;   
        }

        exists |= nr == tr && nc == tc;
        smoke[t - 1] = exists;
    }

    for (const bool& b : smoke) cout << b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}