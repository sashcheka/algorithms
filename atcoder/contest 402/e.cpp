#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    int s, c, p;
    vector<tuple<int, int, double>> problems(n); // score, cost, probability
    for (int i = 0; i < n; i++) {
        cin >> s >> c >> p;
        problems[i] = {s, c, p / 100.0d};
    }

    int combinations = 1 << n;
    vector<vector<double>> dp(combinations, vector<double>(x + 1, 0.0d));

    for (int budget = 1; budget <= x; budget++) {
        for (int mask = 0; mask < combinations; mask++) {
            double curr_cost_best_score = 0.0d;
            for (int bit = 0; bit < n; bit++) {
                if (mask & (1 << bit)) continue; // skip already solved problem

                int s; int c; double p;
                tie(s, c, p) = problems[bit];

                if (c > budget) continue;

                int solved_mask = mask | (1 << bit);
                double success = p * (s + dp[solved_mask][budget - c]);
                double fail = (1 - p) * (dp[mask][budget - c]);

                curr_cost_best_score = max(curr_cost_best_score, success + fail);
            }
            dp[mask][budget] = curr_cost_best_score;
        }
    }

    cout << dp[0][x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6); 

    solve();

    return 0;
}