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
    int n;
    cin >> n;

    int total = 0;
    vector<int> cores(n);
    for (int i = 0; i < n; i++) {
        cin >> cores[i];
        total += cores[i];
    }

    for (int i = 1; i < n - 1; i++) {
        if (cores[i] >= 2) {
            cout << total - 1 << "\n";
            return;
        }
    }

    if (cores[0] > 1 || cores[n - 1] > 1) {
        cout << total - (n - 1) << "\n";
    } else {
        cout << -1 << "\n";
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
