#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_set<int> setik;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        setik.insert(a);
    }
    cout << setik.size() << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
