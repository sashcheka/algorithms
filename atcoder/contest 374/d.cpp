#include <bits/stdc++.h>
using namespace std;

double get_dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double dp(int mask, int idx, int n, int s, int t, const vector<pair<int, int>>& points, vector<vector<double>>& memo) {
    if (mask == (1 << (2 * n)) - 1)
        return 0;

    if (memo[mask][idx] != -1.0)
        return memo[mask][idx];

    double min_time = DBL_MAX;
    int x = points[idx].first;
    int y = points[idx].second;

    for (int i = 0; i < 2 * n; i += 2) {
        if (mask & (1 << i))
            continue;

        double moveF = get_dist(x, y, points[i].first, points[i].second) / s;
        double printF = get_dist(points[i].first, points[i].second, points[i + 1].first, points[i + 1].second) / t;
        double timeF = moveF + printF + dp(mask | (1 << i) | (1 << (i + 1)), i + 1, n, s, t, points, memo);

        double moveS = get_dist(x, y, points[i + 1].first, points[i + 1].second) / s;
        double printS = get_dist(points[i + 1].first, points[i + 1].second, points[i].first, points[i].second) / t;
        double timeS = moveS + printS + dp(mask | (1 << i) | (1 << (i + 1)), i, n, s, t, points, memo);

        min_time = min(min_time, min(timeF, timeS));
    }

    return memo[mask][idx] = min_time;
}

double solve(int n, int s, int t) {
    vector<pair<int, int>> points(2 * n);

    int a, b, c, d;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        points[2 * i] = {a, b};
        points[2 * i + 1] = {c, d};
    }

    vector<vector<double>> memo(1 << (2 * n), vector<double>(2 * n, -1.0));

    double min_time = DBL_MAX;
    for (int i = 0; i < 2 * n; ++i) {
        double initial_move = get_dist(0, 0, points[i].first, points[i].second) / s;
        min_time = min(min_time, initial_move + dp(0, i, n, s, t, points, memo));
    }

    return min_time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s, t;
    cin >> n >> s >> t;

    double time = solve(n, s, t);
    cout << fixed << setprecision(15) << time << "\n";

    return 0;
}
