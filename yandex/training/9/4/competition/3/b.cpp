#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int main() {
    vector<string> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<vector<bool>> used(N, vector<bool>(N, false));
    vector<int> cnt(5, 0);

    auto inside = [&](int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] != '#' || used[i][j]) continue;

            int w = 1, h = 1;

            while (j + w < N && a[i][j + w] == '#') w++;
            while (i + h < N && a[i + h][j] == '#') h++;

            if (w > 1 && h > 1) {
                cout << "NO\n";
                return 0;
            }

            int len = max(w, h);
            if (len > 4) {
                cout << "NO\n";
                return 0;
            }

            if (w > 1) {
                for (int col = j; col < j + w; col++) {
                    if (a[i][col] != '#' || used[i][col]) {
                        cout << "NO\n";
                        return 0;
                    }
                    used[i][col] = true;
                }

                for (int row = i - 1; row <= i + 1; row++) {
                    for (int col = j - 1; col <= j + w; col++) {
                        if (!inside(row, col) || a[row][col] != '#') continue;

                        if (row == i && col >= j && col < j + w) continue;

                        cout << "NO\n";
                        return 0;
                    }
                }
            } else if (h > 1) {
                for (int row = i; row < i + h; row++) {
                    if (a[row][j] != '#' || used[row][j]) {
                        cout << "NO\n";
                        return 0;
                    }
                    used[row][j] = true;
                }

                for (int row = i - 1; row <= i + h; row++) {
                    for (int col = j - 1; col <= j + 1; col++) {
                        if (!inside(row, col) || a[row][col] != '#') continue;

                        if (col == j && row >= i && row < i + h) continue;

                        cout << "NO\n";
                        return 0;
                    }
                }
            } else if (w == 1 && h == 1) {
                used[i][j] = true;

                for (int row = i - 1; row <= i + 1; row++) {
                    for (int col = j - 1; col <= j + 1; col++) {
                        if (!inside(row, col) || a[row][col] != '#') continue;
                        if (row == i && col == j) continue;

                        cout << "NO\n";
                        return 0;
                    }
                }
            }

            cnt[len]++;
        }
    }

    if (cnt[1] == 4 && cnt[2] == 3 && cnt[3] == 2 && cnt[4] == 1) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}