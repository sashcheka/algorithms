#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    set<int> setik;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        setik.insert(a);
    }

    cout << setik.size() << '\n';
    for (auto it = setik.begin(); it != setik.end(); it++) cout << *it << ' ';
 }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}