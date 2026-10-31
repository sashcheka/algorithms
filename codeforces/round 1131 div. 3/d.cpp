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
    int mx = INT_MIN;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    sort(a.begin(), a.end());
    int median = a[n / 2];
    long long cost = 0ll;

    for (int i = 0; i < n; ++i) {
        cost += abs(a[i] - median);
    }

    cout << cost << " " << mx - mn << "\n";

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


// 9 9 8 2 4 4 3 5 3
// target 5?

// 9 9 8

// 8 8 7
// 7 7 6
// 6 6 5
// 5 5 x

// 2 4 4 3 3
// 3 5 5 4 4 
// 4 x x 5 5
// 5 x x x x

// cost = (3 + 3 + 3 + 3) + (5 + 2 + 1) = 11 + 7 = 19
// operations = 7
