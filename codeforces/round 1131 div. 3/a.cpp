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
    int n, m;
    cin >> n >> m;

    vector<int> freq(26);
    string p, q;
    cin >> p >> q;

    for (char ch : p) {
        freq[ch - 'a']++;
    }

    for (char ch : q) {
        freq[ch - 'a']--;
    }

    bool s = false;
    bool i = false;
    bool x = false;
    for (int j = 0; j < 26; j++) {
        if (j + 'a' == 's' && freq[j] == 1) {
            s = true;
        } else if (j + 'a' == 'i' && freq[j] == 1) {
            i = true;
        } else if (j + 'a' == 'x' && freq[j] == 1) {
            x = true;
        } else if (freq[j]) {
            cout << "NO\n";
            return;
        }
    }

    if (s && i && x) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
