#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> interest(n), usefulness(n), mood(n);
    for (int i = 0; i < n; i++) cin >> interest[i];
    for (int i = 0; i < n; i++) cin >> usefulness[i];
    for (int i = 0; i < n; i++) cin >> mood[i];

    vector<vector<int>> algorithms(n, vector<int>(3));
    for (int i = 0; i < n; i++) algorithms[i] = {i + 1, interest[i], usefulness[i]};

    vector<vector<int>> interest_sorted = algorithms;
    sort(interest_sorted.begin(), interest_sorted.end(), [](const auto& a, const auto& b) {
        if (a[1] != b[1]) return a[1] > b[1]; 
        if (a[2] != b[2]) return a[2] > b[2]; 
        return a[0] < b[0]; 
    });

    vector<vector<int>> usefulness_sorted = algorithms;
    sort(usefulness_sorted.begin(), usefulness_sorted.end(), [](const auto& a, const auto& b) {
        if (a[2] != b[2]) return a[2] > b[2]; 
        if (a[1] != b[1]) return a[1] > b[1]; 
        return a[0] < b[0]; 
    });

    vector<bool> studied(n + 1, false);
    vector<int> res;
    int interest_ptr = 0, usefulness_ptr = 0;

    for (int i = 0; i < n; i++) {
        int chosen_idx = -1;

        if (mood[i]) {
            while (usefulness_ptr < n && studied[usefulness_sorted[usefulness_ptr][0]]) {
                usefulness_ptr++;
            }
            chosen_idx = usefulness_sorted[usefulness_ptr][0];
            studied[chosen_idx] = true;
            usefulness_ptr++;
        } else {
            while (interest_ptr < n && studied[interest_sorted[interest_ptr][0]]) {
                interest_ptr++;
            }
            chosen_idx = interest_sorted[interest_ptr][0];
            studied[chosen_idx] = true;
            interest_ptr++;
        }

        res.push_back(chosen_idx);
    }

    for (int i : res) cout << i << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
