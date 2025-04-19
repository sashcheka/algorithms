#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, unordered_set<int>> ingr_to_dishes; // ingr - (dish1, dish2, ...)
    unordered_map<int, int> dish_ingr_count; // dish - ingr_count

    for (int dish = 0; dish < m; dish++) {
        int k;
        cin >> k;

        int ingr;
        for (int j = 0; j < k; j++) {
            cin >> ingr;
            ingr_to_dishes[ingr].insert(dish);
            dish_ingr_count[dish]++;
        }
    }

    int available = 0;
    int del_ingr;
    for (int b = 0; b < n; b++) {
        cin >> del_ingr;
        for (int dish : ingr_to_dishes[del_ingr]) {
            dish_ingr_count[dish]--;
            if (dish_ingr_count[dish] == 0) available++;
        }
        cout << available << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}