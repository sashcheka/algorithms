#include<bits/stdc++.h>

using namespace std;

void bfs(vector<pair<int, int>>& cities, int& k, int& start, int& end) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    vector<bool> visited(cities.size(), false);

    while (!q.empty()) {
        pair<int, int> p = q.front();
        int curr_city = p.first;
        int steps = p.second;
        q.pop();

        if (p.first == end) {
            cout << steps;
            return;
        }

        for (int i = 0; i < cities.size(); i++) {
            if (!visited[i]) {
                long long dist = (long long)abs(cities[curr_city].first - cities[i].first) + abs(cities[curr_city].second - cities[i].second);
                if (dist <= k) {
                    visited[i] = true;
                    q.push({i, steps + 1});
                } 
            }
        }
    }

    cout << -1;
    return;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i].first;
        cin >> cities[i].second;
    }

    int k;
    cin >> k;

    int start, end;
    cin >> start >> end;

    start--;
    end--;

    bfs(cities, k, start, end);
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}
