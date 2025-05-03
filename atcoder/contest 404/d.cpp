#include <bits/stdc++.h>

using namespace std;

long long ans = LLONG_MAX;

void backtrack(int idx, long long curr_cost, vector<int>& animal_counts, const vector<long long>& costs, const vector<vector<int>>& zoo_to_animals) {
    if (idx == zoo_to_animals.size()) {
        bool all_covered = true;

        for (int cnt : animal_counts) {
            if (cnt < 2) {
                all_covered = false;
                break;
            }
        }

        if (all_covered) ans = min(ans, curr_cost);

        return;
    }

    backtrack(idx + 1, curr_cost, animal_counts, costs, zoo_to_animals);

    for (int animal : zoo_to_animals[idx]) animal_counts[animal]++;
    backtrack(idx + 1, curr_cost + costs[idx], animal_counts, costs, zoo_to_animals);
    for (int animal : zoo_to_animals[idx]) animal_counts[animal]--;

    for (int animal : zoo_to_animals[idx]) animal_counts[animal] += 2;
    backtrack(idx + 1, curr_cost + 2 * costs[idx], animal_counts, costs, zoo_to_animals);
    for (int animal : zoo_to_animals[idx]) animal_counts[animal] -= 2;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<long long> costs(n);
    for (int i = 0; i < n; ++i) {
        cin >> costs[i];
    }

    vector<vector<int>> zoo_to_animals(n);
    for (int animal = 0; animal < m; ++animal) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int zoo;
            cin >> zoo;
            zoo--;
            zoo_to_animals[zoo].push_back(animal);
        }
    }

    vector<int> animal_counts(m, 0);
    backtrack(0, 0, animal_counts, costs, zoo_to_animals);

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}