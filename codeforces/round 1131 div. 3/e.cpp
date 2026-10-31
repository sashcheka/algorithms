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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = (i % 2 == 0) ? a[i] : -a[i];
    }

    sort(b.begin(), b.end());
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            sum -= b[i];
        } else {
            sum += b[i];
        }
    }

    cout << sum << "\n";

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
