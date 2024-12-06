#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, b;
    cin >> n >> b;
    
    long long time = 0;
    deque<pair<int, int>> q;

    int a;
    int remain;
    for (int i = 0; i < n; i++) {
        cin >> a;
        q.push_back({a, i});

        remain = b;
        while (!q.empty() && remain >= q.front().first) {
            time += static_cast<long long>(q.front().first) * (i - q.front().second + 1);
            remain -= q.front().first;
            q.pop_front();
        }

        if (!q.empty() && remain < q.front().first) {
            pair<int, int> temp = q.front();
            q.pop_front();
            time += static_cast<long long>(remain) * (i - temp.second + 1);
            temp.first -= remain;
            q.push_front(temp);
        }
    }

    while (!q.empty()) {
        time += static_cast<long long>(q.front().first) * (n - q.front().second + 1);
        q.pop_front();
    }

    cout << time;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
