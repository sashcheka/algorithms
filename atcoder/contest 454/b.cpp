#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        int f;
        cin >> f;
        s.insert(f);
    }
    cout << ((int)s.size() == n ? "Yes" : "No") << "\n";
    cout << ((int)s.size() == m ? "Yes" : "No") << "\n";
    return 0;
}