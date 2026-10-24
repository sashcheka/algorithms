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
#include <climits>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int mn = INT_MAX;
    for (int& x : a) {
        cin >> x;
        mn = min(mn, x);
    }

    if (mn < n) {
        cout << n << "\n";
    } else {
        cout << 0 << "\n";
    }

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
