#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            pq.push(x);
        } else if (type == 2) {
            int top = pq.top();
            pq.pop();
            cout << top << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}