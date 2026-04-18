#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_set<int> s;

    bool all = true;
    for (int i = 0; i < n; i++) {
        int f;
        cin >> f;
        if (!s.insert(f).second) all = false;
    }

    if (all) cout << "Yes" << "\n";
    else cout << "No" << "\n";

    if ((int)s.size() == m) cout << "Yes" << "\n";
    else cout << "No" << "\n";

    return 0;
}