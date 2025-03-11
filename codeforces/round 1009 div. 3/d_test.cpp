#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> centers(n);
    vector<int> radii(n);
    
    for (int i = 0; i < n; i++) cin >> centers[i];
    for (int i = 0; i < n; i++) cin >> radii[i];

    map<int, int> center_radius;
    
    for (int i = 0; i < n; i++) {
        center_radius[centers[i]] = max(center_radius[centers[i]], radii[i]);
    }

    set<pair<int, int>> visited_points;

    for (auto& [cx, r] : center_radius) {
        for (int dx = 0; dx <= r; dx++) {  // Iterate only over dx from 0 to r
            int max_y = (int)sqrt(r * r - dx * dx);
            
            for (int y = 0; y <= max_y; y++) {
                visited_points.insert({cx + dx, y});
                visited_points.insert({cx - dx, y});
                visited_points.insert({cx + dx, -y});
                visited_points.insert({cx - dx, -y});
            }
        }
    }

    cout << visited_points.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
