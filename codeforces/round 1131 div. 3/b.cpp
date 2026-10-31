#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int r, s, p;
    cin >> r >> s >> p;

    char choice;
    if (r >= s && r >= p) {
        choice = 'P';
    } else if (s >= r && s >= p) {
        choice = 'R';
    } else if (p >= r && p >= s) {
        choice = 'S';
    }

    cout << string(r + s + p, choice) << "\n";

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
