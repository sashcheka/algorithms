#include <bits/stdc++.h>

using namespace std;

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int H, W, A, B, C, D;
    cin >> H >> W;

    vector<string> grid(H);
    for (int i = 0; i < H; i++) cin >> grid[i];

    cin >> A >> B >> C >> D;
    A--; B--; C--; D--;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    vector<vector<int>> min_kicks(H, vector<int>(W, INT_MAX));

    pq.emplace(0, A, B);
    min_kicks[A][B] = 0;

    while (!pq.empty()) {
        auto [kicks, i, j] = pq.top();
        pq.pop();

        if (i == C && j == D) {
            cout << kicks << endl;
            return 0;
        }

        if (kicks > min_kicks[i][j]) continue;

        for (int d = 0; d < 4; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && grid[ni][nj] == '.') {
                if (kicks < min_kicks[ni][nj]) {
                    min_kicks[ni][nj] = kicks;
                    pq.emplace(kicks, ni, nj);
                }
            }
        }

        for (int d = 0; d < 4; d++) {
            for (int step = 1; step <= 2; step++) {
                int ni = i + di[d] * step;
                int nj = j + dj[d] * step;
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && grid[ni][nj] == '#') {
                    if (kicks + 1 < min_kicks[ni][nj]) {
                        min_kicks[ni][nj] = kicks + 1;
                        pq.emplace(kicks + 1, ni, nj);
                    }
                }
            }
        }
    }

    cout << -1;
    return 0;
}