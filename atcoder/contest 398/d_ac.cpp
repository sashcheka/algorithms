#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, R, C;
    cin >> n >> R >> C;
    
    string s;
    cin >> s;
    
    vector<pair<int, int>> f(n + 1);
    f[0] = {0, 0};
    
    for (int i = 0; i < n; i++){
        int pos_r = f[i].first, pos_c = f[i].second;
        char dir = s[i];
        
        if (dir == 'N') {
            pos_r--;
        } else if (dir == 'S') {
            pos_r++;
        } else if (dir == 'W') {
            pos_c--;
        } else if (dir == 'E') {
            pos_c++;
        }

        f[i + 1] = {pos_r, pos_c};
    }
    
    map<pair<int,int>, int> firstOccurrence;
    for (int i = 0; i <= n; i++){
        pair<int,int> coord = f[i];

        if (firstOccurrence.find(coord) == firstOccurrence.end()){
            firstOccurrence[coord] = i;
        }
    }
    
    string result(n, '0');
    for (int t = 1; t <= n; t++){
        int target_r = f[t].first - R;
        int target_c = f[t].second - C;

        pair<int,int> target = {target_r, target_c};

        if (firstOccurrence.find(target) != firstOccurrence.end() && firstOccurrence[target] <= t) {
            result[t - 1] = '1';
        }
    }
    
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}
