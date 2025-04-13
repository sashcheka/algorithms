#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int can_build_second_wall(const vector<vector<bool>>& dp, int total_w, int k) {
    for (int w = 1; w < total_w; ++w) {
        bool ok = true;
        for (int c = 0; c < k; ++c) {
            if (!dp[c][w]) {
                ok = false;
                break;
            }
        }
        if (ok) return w;
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> ls(n), cs(n);
    vector<vector<pair<int, int>>> color_bricks(k);
    vector<int> sum_width_per_color(k, 0);

    for (int i = 0; i < n; ++i) {
        int l, c;
        cin >> l >> c;
        --c;
        ls[i] = l;
        cs[i] = c;
        color_bricks[c].emplace_back(l, i + 1);
        sum_width_per_color[c] += l;
    }

    set<int> check(sum_width_per_color.begin(), sum_width_per_color.end());
    if (check.size() != 1) {
        cout << "NO" << endl;
        return 0;
    }

    int max_width = sum_width_per_color[0];
    vector<vector<bool>> dp(k, vector<bool>(max_width + 1, false));
    vector<vector<vector<int>>> path(k, vector<vector<int>>(max_width + 1));

    for (int c = 0; c < k; ++c) dp[c][0] = true;

    for (int c = 0; c < k; ++c) {
        for (auto [l, idx] : color_bricks[c]) {
            for (int cand = max_width; cand >= l; --cand) {
                if (dp[c][cand - l] && !dp[c][cand]) {
                    dp[c][cand] = true;
                    path[c][cand] = path[c][cand - l];
                    path[c][cand].push_back(idx);
                }
            }
        }
    }

    int w = can_build_second_wall(dp, max_width, k);
    if (w == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<int> result;
        for (int c = 0; c < k; ++c) {
            result.insert(result.end(), path[c][w].begin(), path[c][w].end());
        }
        for (int i = 0; i < result.size(); ++i) {
            if (i > 0) cout << ' ';
            cout << result[i];
        }
        cout << endl;
    }

    return 0;
}
