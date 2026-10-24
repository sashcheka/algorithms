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
    int n, k;
    cin >> n >> k;

    vector<int> freq(n + 1);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        freq[val]++;
    }

    int mex = 0;
    int less = 0;
    for (int i = 0; i < n + 1; i++) {
        if (freq[i] == 0) {
            break;
        }

        if (freq[i] >= k) {
            mex++;
            freq[i] -= k;
            less += freq[i];
        } else if (less + freq[i] >= k) {
            mex++;
            freq[i] -= k - less;
            less = freq[i];
        } else {
            break;
        }
    }

    cout << mex << "\n";

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
