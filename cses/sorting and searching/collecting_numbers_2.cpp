#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> nums(n), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        pos[nums[i] - 1] = i;
    }

    int rounds = 1;
    for (int i = 0; i + 1 < n; i++) if (pos[i] > pos[i + 1]) rounds++;

    while (m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        int v = nums[a] - 1;
        int u = nums[b] - 1;

        set<int> affected;
        for (int x : {v, u}) {
            if (x > 0) affected.insert(x - 1);
            if (x < n - 1) affected.insert(x);
        }

        int before = 0;
        for (int i : affected) if (pos[i] > pos[i + 1]) before++;

        swap(nums[a], nums[b]);
        swap(pos[v], pos[u]);

        int after = 0;
        for (int i : affected) if (pos[i] > pos[i + 1]) after++;

        rounds += (after - before);
        cout << rounds << "\n";
    }

    return 0;
}
