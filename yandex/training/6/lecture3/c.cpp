#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    deque<pair<int, int>> dq;
    int a;
    for (int i = 0; i < k; i++) {
        cin >> a;

        while (!dq.empty() && dq.back().first > a) dq.pop_back();
        dq.emplace_back(a, i);
    }

    cout << dq.front().first << '\n';

    for (int i = k; i < n; i++) {
        cin >> a;

        if (!dq.empty() && dq.front().second <= i - k) dq.pop_front();

        while (!dq.empty() && dq.back().first > a) dq.pop_back();
        dq.emplace_back(a, i);

        cout << dq.front().first << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
