#include<bits/stdc++.h>

using namespace std;

void solve() {
    queue<int> q;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            q.push(x);
        } else if (type == 2) {
            cout << q.front() << '\n';
            q.pop();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}