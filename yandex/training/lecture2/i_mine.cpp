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
        if (a[1] != b[1]) return a[1] > b[1]; // interest
        if (a[2] != b[2]) return a[2] > b[2];
        return a[0] < b[0];
    });

    vector<vector<int>> usefulness_sorted = algorithms;
    sort(usefulness_sorted.begin(), usefulness_sorted.end(), [](const auto& a, const auto& b) {
        if (a[2] != b[2]) return a[2] > b[2]; // usefulness
        if (a[1] != b[1]) return a[1] > b[1];
        return a[0] < b[0];
    });

    vector<bool> studied(n + 1, false);
    vector<int> res;

    for (int i = 0; i < n; i++) {
        int chosen_idx = -1;

        if (mood[i]) { // usefulness
            for (const vector<int>& algo : usefulness_sorted) {
                if (!studied[algo[0]]) {
                    chosen_idx = algo[0];
                    studied[chosen_idx] = true;
                    break;
                }
            }
        } else { // interest
            for (const vector<int>& algo : interest_sorted) {
                if (!studied[algo[0]]) {
                    chosen_idx = algo[0];
                    studied[chosen_idx] = true;
                    break;
                }
            }
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
