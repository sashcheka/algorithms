#include <bits/stdc++.h>

using namespace std;

int count_inversions(const vector<int>& arr) {
    int inversions = 0;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                ++inversions;
            }
        }
    }
    return inversions;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int initial_inversions = count_inversions(a);
    int min_inversions = initial_inversions;
    pair<int, int> best_l_r = {1, 1};
    
    for (int l = 0; l < n; ++l) {
        for (int r = l + 1; r < n; ++r) {
            vector<int> modified = a;
            int first = modified[l];
            
            for (int i = l; i < r; ++i) {
                modified[i] = modified[i + 1];
            }
            modified[r] = first;
            
            int inversions = count_inversions(modified);
            
            if (inversions < min_inversions) {
                min_inversions = inversions;
                best_l_r = {l + 1, r + 1};
            }
        }
    }
    
    cout << best_l_r.first << " " << best_l_r.second << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) solve();

    return 0;
}
