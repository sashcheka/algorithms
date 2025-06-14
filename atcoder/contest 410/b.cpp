#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> boxes(n, 0);
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            int smallest_box_idx = -1;
            int smallest_box = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (boxes[j] < smallest_box) {
                    smallest_box = boxes[j];
                    smallest_box_idx = j;
                }
            }
            boxes[smallest_box_idx]++;
            cout << smallest_box_idx + 1 << ' ';
        } else {
            boxes[x - 1]++;
            cout << x << ' ';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}